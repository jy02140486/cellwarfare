#ifndef DRAWCELLS_H
#define DRAWCELLS_H


#include "../Libs/ImpDraw.h"

class drawCells:public ImpDraw
{
public:
void draw(CL_GraphicContext *gc ,float x,float y);
void draw(CL_GraphicContext *gc ,float x,float y,float radious);
drawCells();
protected:

private:


};


#endif
