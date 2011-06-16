#ifndef WC_H
#define WC_H
#include "cells.h"

class Wcells:public cells
{
public:
	void ContactProcess(cells* refc);
	void initialize(defCells* refTemplateC,b2World *world,defBF*refbelong);
	Wcells();
	Wcells(int level);
	int lv;
protected:
private:
	
};

#endif