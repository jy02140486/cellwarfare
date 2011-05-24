#ifndef SCROBJ_H
#define SCROBJ_H

#include "../App/drawScrObj.h"
#include "../Libs/IDraw.h"
#include "../Libs/ents.h"
#include "defBF.h"
#include "../Libs/timer.h"


class ScrObj:public Idraw,public Ents
{
public:
	ScrObj();
	ScrObj* next;
	void draw(CL_GraphicContext *gc);
	bool isCousurOn(CL_Point mouse);
	void update(CL_Point curMouse);
	int refradius;
	defBF* datas;
	CL_Point *pos;
	CL_Point posMouse;

	Timer *timer;

	CL_String *des;

	enum {
		NORMAL=0,
		INTRUDED,
		CANNON,
		LYMPH
	}ObjState;
	
};
#endif