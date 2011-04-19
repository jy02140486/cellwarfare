#ifndef DRAWSCROBJ_H
#define DRAWSCROBJ_H
#include "../libs/impDraw.h"
class drawScrObj:public ImpDraw
{
	 void draw(CL_GraphicContext *gc, float x, float y,float radius);

	
	 void draw(CL_GraphicContext *gc,CL_Point *pos,CL_Colorf colour,int radius);
};
#endif

