#include "DataDefs.h"

DataDefs::DataDefs()
{
	TWC=new defCells();
	TWC->cell_type=defCells::WC;
	TWC->faction=0;
	TWC->reflectR=10;
	TWC->shape.m_radius=TWC->reflectR;

	TTC=new defCells();
	TTC->cell_type=defCells::TC;
	TTC->faction=0;
	TTC->reflectR=10;
	TTC->shape.m_radius=TTC->reflectR;

	TArmored=new defCells();
	TArmored->cell_type=defCells::ARMORED;
	TArmored->faction=1;
	TArmored->reflectR=15;
	TArmored->shape.m_radius=TArmored->reflectR;

	TNaked=new defCells();
	TNaked->cell_type=defCells::NAKED;
	TNaked->faction=1;
	TNaked->reflectR=10;
	TNaked->shape.m_radius=TNaked->reflectR;

	NakedShape.m_radius=10;
	ArmoredShape.m_radius=15;

}