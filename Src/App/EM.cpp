#include "EM.h"

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
	
}

void EM::iniLVs()
{
	//def lv1
	
	lv1.deslv=new CL_String("Stage1");
	lv1.pills=10;
	lv1.time=5;
	lv1.waves=3;

	_levels.push_back(new levels());
	itrLV=_levels.end();
	itrLV--;
	(*itrLV)->initialize(&lv1);


	//def lv2
	
	lv2.deslv=new CL_String("Stage2");
	lv2.pills=5;
	lv2.time=5;
	lv2.waves=4;

	_levels.push_back(new levels());
	itrLV=_levels.end();
	itrLV--;
	(*itrLV)->initialize(&lv2);
	(*itrLV)->lvtimer->func_expired().set(this,&EM::stageclear);
// 
	//def lv3
	
	lv3.deslv=new CL_String("Stage3");
	lv3.pills=5;
	lv3.time=5;
	lv3.waves=5;

	_levels.push_back(new levels());
	itrLV=_levels.end();

	itrLV--;
	(*itrLV)->initialize(&lv3);
	(*itrLV)->lvtimer->func_expired().set(this,&EM::stageclear);

	curLV=*(_levels.begin());
	itrLV=_levels.begin();

	curLV->lvtimer->func_expired().set(this,&EM::stageclear);
	curLV->start();

}

void EM::switchlevel()
{
	(*itrLV)->lvtimer->stop();

		if (++itrLV==_levels.end())
		{
			return;
		}

		curLV=*itrLV;
		curLV->start();

		return;
}

void EM::stageclear()
{
	curLV->lvdes=new CL_String("This stage is clear.");
	Timer *temp=new Timer();
	temp->init(2,false);
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
			itr->stateSwitching();
		}
		break;
	}
	
	if (itrLV==_levels.end())
	{
		return 0;
	}
	return 1;
}

void EM::initScrObjs()
{
	head=new ScrObj();
	itr=head;
	itr->pos=new CL_Point(423,229);

	head->next=new ScrObj();
	itr=itr->next;
	itr->pos=new CL_Point(564,174);

	itr->next=new ScrObj();
	itr=itr->next;
	itr->pos=new CL_Point(573,258);

	itr->next=new ScrObj();
	itr=itr->next;
	itr->pos=new CL_Point(576,363);
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