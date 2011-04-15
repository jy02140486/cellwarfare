#ifndef SCROBJ_H
#define SCROBJ_H

#include "../App/drawScrObj.h"
#include "../Libs/IDraw.h"
#include "../Libs/ents.h"
#include "defBF.h"

class ScrObj:public Idraw,public Ents
{
public:
	ScrObj();
	ScrObj* next;
	void draw(CL_GraphicContext *gc);
	int refradius;
	defBF* datas;
	CL_Point *pos;
	
};
#endif