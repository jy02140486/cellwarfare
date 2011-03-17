#ifndef LEVELS_H
#define LEVELS_H

#include "Box2D/Box2D.h"
#include "../Libs/ents.h"
#include <ClanLib/core.h>

class levels :public Ents,public b2World
{
public:
	void initalize();
	void update();

	levels();

	CL_Timer *lvtimer;
	CL_Font *lvdes;
protected:

private:

};
#endif