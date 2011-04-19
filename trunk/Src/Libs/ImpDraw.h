#ifndef IMPDRAW_H
#define  IMPDRAW_H

#include "../App/precomp.h"

class ImpDraw
{
public:
	 void draw(CL_GraphicContext *gc ,float x,float y);
	 void draw(CL_GraphicContext *gc ,float x,float y,float radius);
protected:
private:
};
#endif