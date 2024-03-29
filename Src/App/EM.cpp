#include "EM.h"
#include "../Libs/RandomVal.h"
#include "globals.h"

void EM::setcurLV(levels *ref)
{
	curLV=ref;
}

void EM::setcurBF(defBF*ref)
{
	curBF=new bf();
	curBF->initialize(ref);
}

EM::EM()
{
	SOselected=NULL;
	MrkBreak=1;
}

void EM::iniLVs()
{
	//def lv1
	
	lv1.deslv=new CL_String("Stage1");
	lv1.pills=10;
	lv1.time=60;
	lv1.waves=3;

	

	_levels.push_back(new levels());
	itrLV=_levels.end();
	itrLV--;
	(*itrLV)->initialize(&lv1);


	//def lv2
	
	lv2.deslv=new CL_String("Stage2");
	lv2.pills=5;
	lv2.time=120;
	lv2.waves=4;

	_levels.push_back(new levels());
	itrLV=_levels.end();
	itrLV--;
	(*itrLV)->initialize(&lv2);
	(*itrLV)->lvtimer->func_expired().set(this,&EM::stageclear);

	//def lv3
	
	lv3.deslv=new CL_String("Stage3");
	lv3.pills=5;
	lv3.time=240;
	lv3.waves=5;

	_levels.push_back(new levels());
	itrLV=_levels.end();

	itrLV--;
	(*itrLV)->initialize(&lv3);
	(*itrLV)->lvtimer->func_expired().set(this,&EM::stageclear);

	curLV=*(_levels.begin());
	itrLV=_levels.begin();

	curLV->lvtimer->func_expired().set(this,&EM::stageclear);

	curLV->defbfs[0].numCannon=4;

	hero=new Hero();
	hero->eventTimer=new Timer();
	hero->eventTimer->init(5,true);
//	hero->eventTimer->func_expired().set(this,&EM::intruding);
	curLV->start();

}


void EM::switchlevel()
{
	(*itrLV)->lvtimer->stop();

		if (++itrLV==_levels.end())
		{
			global_state=GLOBAL_STATE::ALL_CLEAR;
			CL_Timer* vic=new CL_Timer();
			vic->func_expired().set(this,&EM::victory);
			vic->start(6000,false);
			return;
		}

		curLV=*itrLV;

		itr=head;

		for(int i=0;i<4;i++)
		{
			
			itr->ObjState=ScrObj::NORMAL;
			itr->datas=&curLV->defbfs[i];
			itr=itr->next;
		}

		curLV->start();
		hero->HP->val=100;
		hero->ImmunityPoints->val=curLV->lvtimer->length*2+80;
		hero->painkiller->val=curLV->pills;
		
		global_state=STRATGY;
		return;
}

void EM::victory()
{
	MrkBreak=0;
}

void EM::stageclear()
{
	global_state=LVSWITCHING;
	
	curLV->lvdes=new CL_String("This stage is clear.");
	Timer *temp=new Timer();
	temp->init(3,false);
	temp->func_expired().set(this,&EM::switchlevel);
	temp->begin();
}

int EM::updateall(GLOBAL_STATE stateref)
{
	switch(stateref)
	{
	case STRATGY:
		for (itr=head;itr!=NULL;itr=itr->next)
		{
			itr->update(posMouse);
		}
		break;

	case TATICAL:
		curBF->update();
	}
	
	if (hero->HP->val<=0)
	{
		global_state=GAMEOVER;
		CL_Timer* temp=new CL_Timer();
		temp->func_expired().set(this,&EM::defeated);
		temp->start(5000,false);
	}
	return MrkBreak;
}

void EM::defeated()
{
	MrkBreak=0;
}

void EM::initScrObjs()
{
	head=new ScrObj();
	itr=head;
	itr->pos=new CL_Point(423,229);
	itr->datas=&curLV->defbfs[0];
	itr->des=new CL_String("arm");


	head->next=new ScrObj();
	itr=itr->next;
	itr->pos=new CL_Point(564,174);
	itr->datas=&curLV->defbfs[1];
	itr->des=new CL_String("mouth");

	itr->next=new ScrObj();
	itr=itr->next;
	itr->pos=new CL_Point(573,258);
	itr->datas=&curLV->defbfs[2];
	itr->des=new CL_String("breast");

	itr->next=new ScrObj();
	itr=itr->next;
	itr->pos=new CL_Point(576,363);
	itr->datas=&curLV->defbfs[3];
	itr->des=new CL_String("waist");
}

ScrObj* EM::ScrObjTraversal()
{
	for(ScrObj* temp=head;temp!=NULL;temp=temp->next)
	{
		if (temp->isCousurOn(posMouse))
		{
			return temp;
		}
	}
	return NULL;
}

ScrObj* EM::ScrObjTraversal(ScrObj* listhead)
{
	for(ScrObj* temp=listhead;temp!=NULL;temp=temp->next)
	{
		if (temp->isCousurOn(posMouse))
		//temp->isCousurOn(posMouse);
		{
			return temp;
		}
	}
	return NULL;
}

void EM::retreat()
{
	hero->HP->minus(curBF->datas->intruder);

	curBF->datas->intruder=0;
	SOselected->ObjState=ScrObj::NORMAL;

	if (SOselected->timer!=NULL)
		SOselected->timer->stop();
}