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
			}
		}
		break;
	}
}