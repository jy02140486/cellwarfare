#ifndef DEFCELLS_H
#define DEFCELLS_H

#include <Box2D/Box2D.h>


class defCells
{
public:
	
	enum {
		WC=0,
		TC,
		ARMORED,
		NAKED
	}cell_type;

	b2BodyDef def;
	b2CircleShape shape;
	int faction;
	bool living;
	int reflectR;
	defCells();

protected:
private:
};
#endif