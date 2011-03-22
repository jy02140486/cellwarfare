#include "levels.h"

void levels::initialize(defLV* ref)
{
	lvdes=ref->deslv;
	pills=ref->pills;
	waves=ref->waves;
	time=ref->time;
	
	lvtimer=new Timer();
	lvtimer->init(time,true);
}

void levels::update()
{


}

levels::levels():b2World(b2Vec2(0.0f,10.0f),true)
{

}

void levels::start()
{
	lvtimer->begin();
}