#ifndef EM_H
#define EM_H

#include "precomp.h"
#include "../Entities/levels.h"
#include "../Entities/defLV.h"
#include "../Entities/bf.h"
#include "../Entities/defBF.h"
#include "../Entities/ScrObj.h"
#include "../Entities/Hero.h"
#include "globals.h"
#include <list>

class EM
{
public:
	levels *curLV;
	bf *curBF;
	ScrObj* itr,*head,*SOselected;

	std::list<levels*> _levels;
	std::list<levels*>::iterator itrLV;

	Hero *hero;

	void setcurLV(levels* ref);
	void setcurBF(defBF*ref);

	void iniLVs();
	
	void initScrObjs();
	EM();

	void switchlevel();

	int updateall(GLOBAL_STATE stateref);
	void stageclear();
	ScrObj* ScrObjTraversal();
	ScrObj* ScrObjTraversal(ScrObj* listhead);
	void retreat();
	void defeated();
	void victory();
	CL_Point posMouse;

	int MrkBreak;

	defLV lv1;
	defLV lv2;
	defLV lv3;
protected:
private:
};
#endif
