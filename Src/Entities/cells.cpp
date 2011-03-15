#include "cells.h"

void cells::initalize()
{
	_ImpDraw=new drawCells();
}

void cells::initalize(b2BodyDef *def,b2World *world)
{
	_ImpDraw=new drawCells();
	self=(b2Body*)world->CreateBody(def);
	self->SetUserData(this);
}


void cells::update()
{

}

void cells::draw(CL_GraphicContext *gc,float x,float y)
{
	_ImpDraw->draw(gc,x,y,self->GetFixtureList()->GetShape()->m_radius);
}

cells::cells()
{

}