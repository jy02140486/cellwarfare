#include "timer.h"

void Timer::init(int seconds,bool repeatflag)
{
	length=seconds;
	cursecond=0;
}