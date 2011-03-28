#ifndef LEVELS_H
#define LEVELS_H

#include "Box2D/Box2D.h"
#include "../Libs/ents.h"
#include "../Libs/Timer.h"
#include "defLV.h"


class levels :public Ents,public b2World
{
public:
	
	void initialize(defLV* ref);
	void update();
	void start();

	levels();
	bool isVic();

	Timer *lvtimer;


	CL_String *lvdes;
	int pills;
	int waves;
	int curwaves;
	int time;
	
protected:

private:

};
#endif