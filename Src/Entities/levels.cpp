#include "levels.h"

void levels::initialize(defLV* ref)
{
	lvdes=ref->deslv;
	pills=ref->pills;
	waves=ref->waves;
	lvtimer=new CL_Timer();
	lvtimer->start(ref->time*1000,true);
}

void levels::update()
{


}

levels::levels():b2World(b2Vec2(0.0f,10.0f),true)
{

}