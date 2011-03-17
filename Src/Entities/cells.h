#ifndef CELLS_H
#define CELLS_H

#include "../Libs/ents.h"
#include "../Libs/IDraw.h"
#include "../app/drawCells.h"

class cells:public Ents,public Idraw
{
public:

	b2Body *self;
	void update();
	void initialize();
	void initialize(b2BodyDef *def,b2World *world);
	void draw(CL_GraphicContext *gc,float x,float y);
	cells();
protected:
private:

};
#endif