#ifndef EM_H
#define EM_H

#include "precomp.h"
#include "../Entities/levels.h"
#include "../Entities/bf.h"

class EM
{
public:
	levels *curLV;
	bf *curBF;

	void setcurLV(levels* ref);
	void setcurBF();
protected:
private:
};
#endif
