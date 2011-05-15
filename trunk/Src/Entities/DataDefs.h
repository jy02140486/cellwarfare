#ifndef DATADEFS_H
#define DATADEFS_H

#include "cells.h"
#include <Box2D/Box2D.h>

class DataDefs
{
public:
	b2BodyDef cell;

	defCells *TWC;
	defCells*TTC;
	defCells*TArmored;
	defCells*TNaked;

	b2BodyDef def;

	b2CircleShape NakedShape;
	b2CircleShape ArmoredShape;

	DataDefs();
protected:
private:
};
#endif