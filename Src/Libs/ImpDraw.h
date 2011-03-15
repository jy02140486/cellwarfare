#ifndef IMPDRAW_H
#define  IMPDRAW_H

#include "../App/precomp.h"

class ImpDraw
{
public:
	virtual void draw(CL_GraphicContext *gc ,float x,float y);
	virtual void draw(CL_GraphicContext *gc ,float x,float y,float radius);
protected:
private:
};
#endif