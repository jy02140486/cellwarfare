#include "drawScrObj.h"

void drawScrObj::draw(CL_GraphicContext *gc, float x, float y,float radius)
{
	CL_Draw::circle(*gc,
		x,
		y,
		radius,
		CL_Colorf::blueviolet);
}

/*
void drawScrObj::draw(CL_GraphicContext *gc,CL_Point pos,GLOBAL_STATE state,int radius)
{
	CL_Draw::circle(*gc,pos->x,pos->y,refradius,CL_Colorf(255.0f,0.0f,0.0f,0.4f));
	switch(ObjState)
	{
	case MOUSEON:
		CL_Draw::circle(*gc,pos->x,pos->y,refradius/2,CL_Colorf(0.0f,0.0f,255.0f,0.6f));
		break;
	}
}*/
void drawScrObj::draw(CL_GraphicContext *gc,CL_Point *pos,CL_Colorf colour,int radius)
{
	CL_Draw::circle(*gc,pos->x,pos->y,radius,colour);
}
