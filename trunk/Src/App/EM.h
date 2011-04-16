#ifndef EM_H
#define EM_H

#include "precomp.h"
#include "../Entities/levels.h"
#include "../Entities/defLV.h"
#include "../Entities/bf.h"
#include "../Entities/defBF.h"
#include "../Entities/ScrObj.h"
#include <list>

class EM
{
public:
	levels *curLV;
	bf *curBF;
	ScrObj* itr,*head;

	std::list<levels*> _levels;
	std::list<levels*>::iterator itrLV;

	void setcurLV(levels* ref);
	void setcurBF(defBF*ref);

	void iniLVs();
	
	void initScrObjs();
	EM();
	void switchlevel();
	int updateall();
	void stageclear();

	CL_Point posMouse;

	defLV lv1;
	defLV lv2;
	defLV lv3;
protected:
private:
};
#endif
