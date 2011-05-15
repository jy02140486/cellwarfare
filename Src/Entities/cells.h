#ifndef CELLS_H
#define CELLS_H

#include "../Libs/ents.h"
#include "../Libs/IDraw.h"
#include "../app/drawCells.h"
#include "defBF.h"
#include "defCells.h"

class cells:public Ents,public Idraw
{

public:
	enum {
		WC=0,
		TC,
		ARMORED,
		NAKED
	}cell_type;

	b2Body *self;
	void update();
	void initialize();
	void initialize(b2World *world);
	void initialize(defCells* ref,b2World *world);
	void draw(CL_GraphicContext *gc,float x,float y);





	int faction;
	bool living;
	int reflectR;

	defBF *belong;

	//bool isalive(){return living;}

	cells();
	void Draw(CL_GraphicContext *gc);
protected:
private:

};
#endif