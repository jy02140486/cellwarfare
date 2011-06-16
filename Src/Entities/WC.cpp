#include "WC.h"
#include "../Libs/RandomVal.h"

void Wcells::ContactProcess(cells* refc)
{
	int probablity=RandomVal::randombool();

	switch(refc->cell_type)
	{
	case ARMORED:
		if (probablity)
		{
			this->waste();
			
		}
		refc->waste();
		lv--;
		break;
	case NAKED:
		probablity=RandomVal::randombool();
		if (probablity)
		{
			refc->waste();
			probablity=RandomVal::randombool();
			if (probablity)
			{
				this->waste();
				lv--;
			}
		}
		break;
	}
}

void Wcells::initialize(defCells* refTemplateC,b2World *world,defBF*refbelong)
{
	int primalR=refTemplateC->shape.m_radius;
	refTemplateC->shape.m_radius=5+lv*5;
	this->cells::initialize(refTemplateC,world,refbelong);
	refTemplateC->shape.m_radius=primalR;
}

Wcells::Wcells()
{
	lv=RandomVal::int_from_to(1,4);
}

Wcells::Wcells(int level)
{
	lv=level;
}