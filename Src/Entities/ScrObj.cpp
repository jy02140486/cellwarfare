#include "ScrObj.h"


ScrObj::ScrObj()
{
	refradius =20;
	next=NULL;
	timer=NULL;
}

void ScrObj::draw(CL_GraphicContext *gc)
{
	CL_Draw::circle(*gc,pos->x,pos->y,refradius,CL_Colorf(255.0f,0.0f,0.0f,0.4f));
	switch(ObjState)
	{
	case CANNON:
		CL_Draw::circle(*gc,pos->x,pos->y,refradius,CL_Colorf::gray);
		break;
	case INTRUDED:
		CL_Draw::circle(*gc,pos->x,pos->y,refradius,CL_Colorf::burlywood);
		break;
	case LYMPH:
		CL_Draw::circle(*gc,pos->x,pos->y,refradius,CL_Colorf::yellow);
	}
	if (isCousurOn(posMouse))
	{
		CL_Draw::circle(*gc,pos->x,pos->y,refradius*0.4,CL_Colorf::green);
	}
}

bool ScrObj::isCousurOn(CL_Point mouse)
{
	if (pos->distance(mouse)<refradius)
	{
		return true;
	}else return false;
}



void ScrObj::update(CL_Point curMouse)
{
	posMouse=curMouse;
}
