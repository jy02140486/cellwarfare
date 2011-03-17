#include "bf.h"

void bf::initialize()
{
	_ImpDraw=new drawBF();
}

void bf::update()
{

}

void bf::draw(CL_GraphicContext *gc,float x,float y)
{
//	_ImpDraw->draw(gc,x,y);
}

void bf::initialize(defBF*ref)
{
	_ImpDraw=new drawBF();
}
