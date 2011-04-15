#include "ScrObj.h"


ScrObj::ScrObj()
{
	_ImpDraw=new drawScrObj();
	refradius =10;
	next=NULL;
}

void ScrObj::draw(CL_GraphicContext *gc)
{
	CL_Draw::circle(*gc,pos->x,pos->y,refradius,CL_Colorf::red);
}