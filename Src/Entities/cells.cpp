#include "cells.h"

void cells::initalize()
{
	_ImpDraw=new drawCells();
}

void cells::update()
{

}

void cells::draw(CL_GraphicContext *gc,float x,float y)
{
	_ImpDraw->draw(gc,x,y);
}

