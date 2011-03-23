#ifndef EM_H
#define EM_H

#include "precomp.h"
#include "../Entities/levels.h"
#include "../Entities/defLV.h"
#include "../Entities/bf.h"
#include "../Entities/defBF.h"

#include <list>

class EM
{
public:
	levels *curLV;
	bf *curBF;

	std::list<levels*> _levels;
	std::list<levels*>::iterator itrLV;

	void setcurLV(levels* ref);
	void setcurBF(defBF*ref);

	void iniLVs();
	CL_Font *lvdes;

	EM();
	int switchlevel(bool vic_flag);

	CL_Callback_v0 callback;

	defLV lv1;
	defLV lv2;
	defLV lv3;
protected:
private:
};
#endif
