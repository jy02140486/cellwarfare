#ifndef IDRAW_H
#define	IDRAW_H

#include "../app/precomp.h"
#include "ImpDraw.h"

class   Idraw
{
  
public:
// 	virtual void draw(CL_GraphicContext *gc)=0;
	Idraw();
	ImpDraw *_ImpDraw;
};
#endif
