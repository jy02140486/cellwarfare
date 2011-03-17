#include "levels.h"

void levels::initalize()
{
	lvtimer=new CL_Timer();
	lvtimer->start(60,true);
}

void levels::update()
{


}

levels::levels():b2World(b2Vec2(0.0f,10.0f),true)
{

}