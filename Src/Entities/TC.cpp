#include "TC.h"
#include "../Libs/RandomVal.h"

void Tcells::ContactProcess(cells* refc)
{
	switch(refc->cell_type)
	{
	case NAKED:
		int probablity=RandomVal::randombool();
		if (probablity)
		{
			refc->waste();
		}
	}
	
}