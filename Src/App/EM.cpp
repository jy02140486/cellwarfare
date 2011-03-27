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
	lv2.time=30;
	lv2.waves=4;

	_levels.push_back(new levels());
	itrLV=_levels.end();
	itrLV--;
	(*itrLV)->initialize(&lv2);
	(*itrLV)->lvtimer->func_expired().set(this,&EM::switchlevel);
// 
	//def lv3
	
	lv3.deslv=new CL_String("Stage3");
	lv3.pills=5;
	lv3.time=25;
	lv3.waves=5;

	_levels.push_back(new levels());
	itrLV=_levels.end();
	itrLV--;
	(*itrLV)->initialize(&lv3);
	(*itrLV)->lvtimer->func_expired().set(this,&EM::testtrigger);

	curLV=*(_levels.begin());
	itrLV=_levels.begin();
// 
// 	for (;itrLV!=_levels.end();itrLV++)
// 	{
// 		CL_Console::write_line((*itrLV)->lvdes->data());
// 	}
// 
// 	itrLV=_levels.begin();

	curLV->lvtimer->func_expired().set(this,&EM::switchlevel);
	curLV->start();


}

void EM::switchlevel()
{
	(*itrLV)->lvtimer->stop();
	if (true)
	{
		if (itrLV++==_levels.end())
		{
			return;
		}

// 		CL_Console
// 			::write_line("%1",curLV->time);
		curLV=*itrLV;
		CL_Console::write_line(CL_StringRef(*curLV->lvdes));
		curLV->start();

		return;
	}else return ;
}

void EM::testtrigger()
{
	CL_Console::write_line("crap");
}