#include "bf.h"
#include "cells.h"

void bf::initialize()
{
	
}

void bf::update()
{
	if (world!=NULL)
	{
		world->Step(1/60.0f,40,40);
	}
}


void bf::initialize(defBF*ref)
{
	world=new b2World(b2Vec2(0.0f,0.0f),true);
	
	if (ref->celldeployed>0)
	{
		cells* temp;
		b2BodyDef def;
		for (int i=0;i<ref->celldeployed;i++)
		{
			temp=new cells();
			temp->initialize(world);
		}
	}
}

bf::bf()
{
	world=NULL;

}

void bf::Draw(CL_GraphicContext *gc)
{

	for (b2Body* bbbb=world->GetBodyList();bbbb!=NULL;bbbb=bbbb->GetNext())
	{
			((cells*)(bbbb->GetUserData()))->Draw(gc);
	}
}
