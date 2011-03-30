#include "bf.h"

void bf::initialize()
{
	_ImpDraw=new drawBF();
}

void bf::update()
{
	if (world!=NULL)
	{
		world->Step(1/60.0f,40,40);
	}
}

void bf::draw(CL_GraphicContext *gc,float x,float y)
{
//	_ImpDraw->draw(gc,x,y);
}

void bf::initialize(defBF*ref)
{
	_ImpDraw=new drawBF();
	world=new b2World(b2Vec2(0.0f,0.0f),true);
	for (int i=0;i<ref->celldeployed;i++)
	{
		
	}
}

bf::bf()
{
	world=NULL;
	_ImpDraw=NULL;
}