#ifndef HERO_H
#define HERO_H
#include "../Libs/ents.h"
#include "../Libs/NatrualNum.h"
#include "../Libs/timer.h"

class Hero:public Ents
{
public:
	NatrualNum* HP;
	NatrualNum* painkiller;
	NatrualNum* ImmunityPoints;
	Timer* eventTimer;
	Hero();
protected:
private:
};
#endif