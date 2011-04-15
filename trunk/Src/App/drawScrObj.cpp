#include "drawScrObj.h"

void drawScrObj::draw(CL_GraphicContext *gc, float x, float y,float radius)
{
	CL_Draw::circle(*gc,
		x,
		y,
		radius,
		CL_Colorf::blueviolet);
}