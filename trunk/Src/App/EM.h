#ifndef EM_H
#define EM_H

#include "precomp.h"
#include "../Entities/levels.h"
#include "../Entities/bf.h"
#include "../Entities/defBF.h"

class EM
{
public:
	levels *curLV;
	bf *curBF;

	void setcurLV(levels* ref);
	void setcurBF(defBF*ref);

	EM();
protected:
private:
};
#endif
