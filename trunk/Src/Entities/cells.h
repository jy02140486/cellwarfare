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
	void initialize(b2BodyDef *odef,b2World *world);
	void initialize(b2World *world);
	void initialize(b2World *world,int faction);
	void draw(CL_GraphicContext *gc,float x,float y);

	b2BodyDef def;
	b2CircleShape shape;
	int faction;

	cells();
	void Draw(CL_GraphicContext *gc);
protected:
private:

};
#endif