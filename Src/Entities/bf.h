#ifndef BF_H
#define BF_H

#include "../Libs/ents.h"
#include "../Libs/IDraw.h"
#include "defBF.h"
#include "../App/drawBF.h"
#include <Box2D/Box2D.h>


class bf:public Ents,public Idraw
{
public:
	b2World* world;

	void initialize();
	void initialize(defBF *ref);
	void update();
	void draw(CL_GraphicContext *gc,float x,float y);
	bf();
	int intruders;
	int celldeployed;

protected:
private:
	
};
#endif