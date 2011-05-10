#include "ScrObj.h"


ScrObj::ScrObj()
{
	_ImpDraw=new drawScrObj();
	refradius =20;
	next=NULL;

}

void ScrObj::draw(CL_GraphicContext *gc)
{
	CL_Draw::circle(*gc,pos->x,pos->y,refradius,CL_Colorf(255.0f,0.0f,0.0f,0.4f));
	switch(ObjState)
	{
	case MOUSEON:
		CL_Draw::circle(*gc,pos->x,pos->y,refradius/2,CL_Colorf(0.0f,0.0f,255.0f,0.6f));
		break;
	case SELECTED:
		CL_Draw::circle(*gc,pos->x,pos->y,refradius/2,CL_Colorf(0.0f,255.0f,0.0f,0.6f));
		break;
	case CANNON:
		CL_Draw::circle(*gc,pos->x,pos->y,refradius,CL_Colorf::gray);
		break;
	case INTRUDED:
		CL_Draw::circle(*gc,pos->x,pos->y,refradius,CL_Colorf::burlywood);
		break;

	}
}

bool ScrObj::isCousurOn(CL_Point mouse)
{
	if (pos->distance(mouse)<refradius)
	{
		return true;
	}else return false;
}

void ScrObj::stateSwitching()
{
	if (isCousurOn(posMouse)&&ObjState!=SELECTED)
	{
		ObjState=MOUSEON;
	}else if(ObjState!=SELECTED)
		ObjState=NORMAL;
	if(datas->intruder>0)
		ObjState=INTRUDED;
}

void ScrObj::update(CL_Point curMouse)
{
	posMouse=curMouse;
}
