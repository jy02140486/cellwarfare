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
	inline bool isCousurOn(CL_Point mouse);
	void update(CL_Point curMouse);
	void stateSwitching();
	int refradius;
	defBF* datas;
	CL_Point *pos;
	CL_Point posMouse;

	CL_String *des;

	enum {
		NORMAL=0,
		MOUSEON,
		INTRUDED,
		SELECTED
	}ObjState;
	
};
#endif