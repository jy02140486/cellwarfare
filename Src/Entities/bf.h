#ifndef BF_H
#define BF_H

#include "../Libs/ents.h"
#include "defBF.h"
#include <Box2D/Box2D.h>


class bf:public Ents
{

public:
	b2World* world;

	void initialize();
	void initialize(defBF *ref);
	void update();

	bf();
	void Draw(CL_GraphicContext &gc);
	void DrawEdgy(CL_GraphicContext *gc,b2Body *bodyref);
	void DrawObjs(CL_GraphicContext *gc,b2Body* bodyref);
	void checkalive();

	int intruders;
	int celldeployed;

	CL_Timer* checkTimer;

protected:
private:
	
};
#endif