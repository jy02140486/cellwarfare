#ifndef CELLS_H
#define CELLS_H

#include "../Libs/ents.h"
#include "../Libs/IDraw.h"
#include "drawCells.h"

class cells:public Ents,public Idraw
{
public:

	void update();
	void initalize();
	void draw(CL_GraphicContext *gc,float x,float y);
	cells();
protected:
private:

};
#endif