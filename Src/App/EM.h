#ifndef EM_H
#define EM_H

#include "precomp.h"
#include "../Entities/levels.h"
#include "../Entities/bf.h"
#include "../Entities/defBF.h"

#include <list>

class EM
{
public:
	levels *curLV;
	bf *curBF;
	std::list<levels> _levels;

	void setcurLV(levels* ref);
	void setcurBF(defBF*ref);

	

	EM();
protected:
private:
};
#endif
