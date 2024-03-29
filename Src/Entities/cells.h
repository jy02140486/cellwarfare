#ifndef CELLS_H
#define CELLS_H

#include "../Libs/ents.h"
#include "../Libs/IDraw.h"
#include "defBF.h"
#include "defCells.h"

class cells:public Ents
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

	virtual void initialize(defCells* ref,b2World *world,defBF*belong);
	void draw(CL_GraphicContext *gc,float x,float y);

	int faction;
	bool living;
	int reflectR;

	defBF *belong;

	//bool isalive(){return living;}

	cells();
	void Draw(CL_GraphicContext *gc);
	virtual void waste();
	virtual void ContactProcess(cells* refc);

protected:
private:

};
#endif