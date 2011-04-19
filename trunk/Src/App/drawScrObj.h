#ifndef DRAWSCROBJ_H
#define DRAWSCROBJ_H
#include "../libs/impDraw.h"
class drawScrObj:public ImpDraw
{
	virtual void draw(CL_GraphicContext *gc, float x, float y,float radius);

	
	virtual void draw(CL_GraphicContext *gc,CL_Point *pos,CL_Colorf colour,int radius);
};
#endif

