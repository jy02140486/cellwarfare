#include "timer.h"

void Timer::init(int seconds,bool repeatflag)
{
	length=seconds;
	cursecond=0;
}

int Timer::get_curSec()
{
	return (CL_System::get_time()-startflag)/1000;
}

void Timer::begin()
{
	startflag=CL_System::get_time();
	start(length*1000);
}

Timer::Timer()
{

}