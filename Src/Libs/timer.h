#ifndef TIMER_H
#define TIMER_H

#include <ClanLib/core.h>
class Timer:public CL_Timer
{
public:
	int length;
	int cursecond;
	int secondsleft;

	int startflag;
	void init(int seconds,bool repeatflag);
	int get_curSec();
	void begin();
	Timer();
protected:
private:
};
#endif