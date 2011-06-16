#include "bf.h"

#include "../App/DestructionListener.h"
#include "../App/globals.h"
#include "../Libs/Converter.h"
#include "TC.h"
#include "WC.h"
#include "Armored.h"
#include "Naked.h"

int i=0;

bf::~bf()
{
	delete world;
	checkTimer->func_expired().set(NULL);
	delete checkTimer;
}

void bf::initialize()
{
	
}

void bf::checkalive(){
 	if (global_state==TATICAL)
		if (checkTimer!=NULL)
		checkTimer->startflag=CL_System::get_time();
}

void bf::update()
{
	if (world!=NULL)
	{
		world->Step(1/60.0f,60,60);
	}
	
  	cells*tc=NULL;
	
	b2Body*temp=world->GetBodyList();
	while (temp!=NULL)
	{
	
		if (temp==NULL)
		{
			break;
		}
		if (temp->GetType()==b2_dynamicBody)
		{
			tc=(cells*)temp->GetUserData();
		}
		else {
			temp=temp->GetNext();
			continue;
		}

		if (tc->living)
		{
			temp=temp->GetNext();
			continue;
		}
		else {
			b2Body* t2=temp->GetNext();
		
			if (tc->faction==0)
			{
				datas->celllaunched--;
			}else
				datas->intruder--;
		

			if (tc->cell_type==cells::ARMORED)
			{
					cells* tec=new cells();
					TCells.TNaked->def.position=temp->GetPosition();
					tec->initialize(TCells.TNaked,world,datas);
					tec->self->SetLinearVelocity(temp->GetLinearVelocity());
			}
			
			if (tc->cell_type==cells::WC)
			{
				Wcells* curwc=(Wcells*)tc->self->GetUserData();
				Wcells *twc=new Wcells(curwc->lv-1);
				if (twc->lv<=0)
				{
					delete temp->GetUserData();
				
					delete twc;
					world->DestroyBody(temp);
					temp=t2;
					temp=temp->GetNext();
					continue;
				}
				TCells.TWC->def.position=temp->GetPosition();
				twc->initialize(TCells.TWC,world,datas);
				twc->self->SetLinearVelocity(temp->GetLinearVelocity());

			}
			delete temp->GetUserData();
			world->DestroyBody(temp);
			temp=t2;
// 			CL_Console::write_line("%1 celllaunched left",celllaunched);
// 			CL_Console::write_line("%1 cellsdeployed left",celldeployed);
// 			CL_Console::write_line("%1 intruders left",intruders);

			continue;
		}
		temp=temp->GetNext();
	}
}


void bf::initialize(defBF*ref)
{
	world=new b2World(b2Vec2(0.0f,0.0f),true);

	datas=ref;

	intrudersGeneration();

	b2BodyDef edgedef;
	edgedef.type=b2_staticBody;
	edgedef.position=b2Vec2(310,40);
	b2Body *edge;
	edge=(b2Body*)world->CreateBody(&edgedef);
	b2PolygonShape edgeshape;

	edgeshape.SetAsEdge(b2Vec2(0,0),b2Vec2(480,0));
	b2Fixture* temp=edge->CreateFixture(&edgeshape,0);
	temp->SetRestitution(6.0);

	edgeshape.SetAsEdge(b2Vec2(0,0),b2Vec2(0,500));
	temp=edge->CreateFixture(&edgeshape,0);
	temp->SetRestitution(6.0);

	edgeshape.SetAsEdge(b2Vec2(0,500),b2Vec2(480,500));
	temp=edge->CreateFixture(&edgeshape,0);
	temp->SetRestitution(6.0);

	edgeshape.SetAsEdge(b2Vec2(480,0),b2Vec2(480,500));
	temp=edge->CreateFixture(&edgeshape,0);
	temp->SetRestitution(6.0);

	world->SetContactListener(new DestructionListener());

	checkTimer=new Timer();

	checkTimer->init(2,true);
	checkTimer->func_expired().set(this,&bf::checkalive);
	checkTimer->begin(true);

	head=new ScrObj();
	head->pos=RandomVal::randomPointi(330,60,780,510);
	head->refradius=10;
	head->ObjState=ScrObj::CANNON;
	head->next=new ScrObj();
	itr=head;
	
	for(int i=0;i<ref->numCannon;i++)
	{
		itr=itr->next;
		itr->pos=RandomVal::randomPointi(330,60,780,510);
		itr->refradius=10;

		if(RandomVal::randombool())
			itr->ObjState=ScrObj::CANNON;
		else 
			itr->ObjState=ScrObj::LYMPH;

		if (i==ref->numCannon-1)
		{
			itr->next=NULL;
		}else
		itr->next=new ScrObj();
	}
}


bf::bf()
{
	world=NULL;
	checkTimer=NULL;
	SOselected=NULL;


}

void bf::DrawObjs(CL_GraphicContext *gc,b2Body* bodyref)
{

	cells*temp=((cells*)(bodyref->GetUserData()));

	if (temp!=NULL)
		temp->Draw(gc);


}

void bf::DrawEdgy(CL_GraphicContext *gc,b2Body *bodyref)
{
	CL_Vec4f red_color(1.0f, 0.0f, 0.0f, 1.0f);
	CL_Vec4f green_color(0.0f, 1.0f, 0.0f, 1.0f);
	CL_Vec4f black_color(0.0f, 0.0f,0.0f, 1.0f);

	CL_Vec2i positions[8];
	CL_Vec4f colors[] = { red_color, green_color,red_color, green_color,red_color, green_color,red_color, green_color};
	CL_Vec4f ground[]={black_color,black_color,black_color,black_color,black_color,black_color,black_color,black_color};

	for (b2Fixture* fixture=bodyref->GetFixtureList();fixture!=NULL;fixture=fixture->GetNext())
	{
	
	b2PolygonShape* shape=(b2PolygonShape*)fixture->GetShape();
	const int vn=shape->GetVertexCount();
	float32 angle=b2_pi/shape->m_vertexCount;

	b2Transform tmptf=bodyref->GetTransform();
	b2Vec2 tmpvec;

	for (int i=0;i<vn;i++)
	{
		tmpvec=b2Mul(tmptf,shape->GetVertex(i));
		positions[i]=CL_Vec2f(tmpvec.x,tmpvec.y);	
	}


	CL_PrimitivesArray vecs(*gc);

	vecs.set_attributes(0,positions);


// 	if (bodyref->GetType()==b2_dynamicBody)
// 		vecs.set_attributes(1,colors);
// 	else
	vecs.set_attributes(1,colors);

	gc->set_program_object(cl_program_color_only);
	gc->draw_primitives(cl_line_loop,vn,vecs);
	}
}


void bf::Draw(CL_GraphicContext &gc)
{
	CL_Gradient color(CL_Colorf::mediumspringgreen, CL_Colorf::honeydew);

	for (b2Body* bbbb=world->GetBodyList();bbbb!=NULL;bbbb=bbbb->GetNext())
	{
		if (bbbb->GetFixtureList()->GetShape()->GetType()==b2Shape::e_circle)
			DrawObjs(&gc,bbbb);
		else if(bbbb->GetType()==b2_staticBody)
			DrawEdgy(&gc,bbbb);
		else if(bbbb->IsBullet())
			CL_Draw::circle(gc,
			bbbb->GetPosition().x,
			bbbb->GetPosition().y,
			2,
			CL_Colorf::burlywood);

	}
}


void bf::launchWC(b2Vec2 dir)
{
	cells* tc=new Wcells();
	int x=SOselected->pos->x;
	int y=SOselected->pos->y;
	TCells.TWC->def.position.Set(x,y);
	tc->initialize(TCells.TWC,world,datas);
	dir;
	tc->self->GetPosition();
	b2Vec2 FVelocity(dir.x*1000,dir.y*1000);
	tc->self->SetLinearVelocity(FVelocity);
}

void bf::launchTC(b2Vec2 dir)
{
	cells* tc=new Tcells();
	int x=SOselected->pos->x;
	int y=SOselected->pos->y;
	TCells.TTC->def.position.Set(x,y);
	tc->initialize(TCells.TTC,world,datas);
	dir;
	tc->self->GetPosition();
	b2Vec2 FVelocity(dir.x*1000,dir.y*1000);
	tc->self->SetLinearVelocity(FVelocity);
}

void bf::showVD(b2Vec2 dir)
{
	b2BodyDef tdef;
	tdef.bullet=true;
	tdef.position=Converter::Vec2from_c_to_b(*SOselected->pos);
	tdef.linearVelocity.Set(dir.x*1000,dir.y*1000);

	b2Body *tbd=world->CreateBody(&tdef);
	b2CircleShape tcs;
	tcs.m_radius=2;

	b2Fixture* tf=tbd->CreateFixture(&tcs,0);

	tbd->SetUserData(NULL);

	b2Filter tfilter;
	tfilter.groupIndex=10;
	tf->SetFilterData(tfilter);
	
}

void bf::intrudersGeneration()
{
	int probability=RandomVal::int_from_to(20,90);
	int dice;
	
	for(int i=0;i<datas->intruder;i++)
	{
		dice=RandomVal::int_from_to(1,100);
		if (dice>probability)
		{
			cells* tc=new armored();
			TCells.TArmored->def.position=Converter::Vec2from_c_to_b(*RandomVal::randomPointi(320,50,500,500));
			tc->initialize(TCells.TArmored,world,datas);
			tc->self->SetLinearVelocity(RandomVal::randomvec(100));
		}
		else{
			cells* tc=new cells();
			TCells.TNaked->def.position=Converter::Vec2from_c_to_b(*RandomVal::randomPointi(320,50,500,500));
			tc->initialize(TCells.TNaked,world,datas);
			tc->self->SetLinearVelocity(RandomVal::randomvec(100));
		}
	}
}

