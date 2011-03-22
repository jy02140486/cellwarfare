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
	lv1.time=20;
	lv1.waves=3;

	_levels.push_back(new levels());
	itrLV=_levels.end();
	itrLV--;
	(*itrLV)->initialize(&lv1);


	//def lv2
	
	lv1.deslv=new CL_String("Stage2");
	lv1.pills=5;
	lv1.time=30;
	lv1.waves=4;

	_levels.push_back(new levels());
	itrLV=_levels.end();
	itrLV--;
	(*itrLV)->initialize(&lv2);
// 
	//def lv3
	
	lv1.deslv=new CL_String("Stage3");
	lv1.pills=5;
	lv1.time=25;
	lv1.waves=5;

	_levels.push_back(new levels());
	itrLV=_levels.end();
	itrLV--;
	(*itrLV)->initialize(&lv3);

	curLV=*(_levels.begin());
	itrLV=_levels.begin();

	curLV->start();


 

}