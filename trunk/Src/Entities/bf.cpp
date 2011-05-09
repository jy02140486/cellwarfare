#include "bf.h"
#include "cells.h"
#include "../App/DestructionListener.h"
#include "../App/globals.h"

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
		world->Step(1/60.0f,40,40);
	}

  	cells*tc=NULL;

// 	for(b2Body*temp=world->GetBodyList();temp!=NULL;temp=temp->GetNext())
// 	{
// 		CL_Console::write_line("%1",i++);
// 		if (temp==NULL)
// 		{
// 			break;
// 		}
// 		if (temp->GetType()==b2_dynamicBody)
// 		{
// 			tc=(cells*)temp->GetUserData();
// 		}
// 		else continue;
// 
// 		if(tc!=NULL)
// 		if (tc->living)
// 		{
// 			continue;
// 		}
// 		else {
// 			b2Body* t2=temp->GetNext();
// 			delete temp->GetUserData();
// 			world->DestroyBody(temp);
// 			temp=t2;
//  		}
// 
// 		
// 	}

	
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
				celllaunched--;
			}else
				intruders--;
			delete temp->GetUserData();
			world->DestroyBody(temp);
			temp=t2;

// 
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
	
	if (ref->celllaunched>0)
	{
		cells* temp;
		b2BodyDef def;
		for (int i=0;i<ref->celllaunched;i++)
		{
			temp=new cells();
			temp->initialize(world);
			temp->belong=ref;
		}
	}

	if (ref->intruder>0)
	{
		cells* temp;
		b2BodyDef def;
		for (int i=0;i<ref->intruder;i++)
		{
			temp=new cells();
			temp->initialize(world,1);
			temp->belong=ref;
		}
	}

	celldeployed=ref->celldeployed;
	intruders=ref->intruder;
	celllaunched=ref->celllaunched;

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
		itr->ObjState=ScrObj::CANNON;
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
		else
			DrawEdgy(&gc,bbbb);

// 		CL_Draw::circle(gc,
// 			bbbb->GetPosition().x,
// 			bbbb->GetPosition().y,
// 		bbbb->GetFixtureList()->GetShape()->m_radius,
// 			CL_Colorf::blueviolet);
	}
}

void bf::DataSynchronize(defBF*ref)
{
	ref->celllaunched=celllaunched;
	ref->intruder=intruders;
	ref->celldeployed=celldeployed;
}