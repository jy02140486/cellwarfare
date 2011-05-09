#include "Hero.h"

Hero::Hero()
{
	HP=new NatrualNum(100);
	painkiller=new NatrualNum(4);
	eventTimer=new Timer();
}

