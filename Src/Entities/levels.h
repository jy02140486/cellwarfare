#ifndef LEVELS_H
#define LEVELS_H

#include "Box2D/Box2D.h"
#include "../Libs/ents.h"
#include "defLV.h"
#include <ClanLib/core.h>

class levels :public Ents,public b2World
{
public:
	
	void initialize(defLV* ref);
	void update();

	levels();
	
	CL_Timer *lvtimer;
	CL_String *lvdes;
	int pills;
	int waves;
	int curwaves;
	
protected:

private:

};
#endif