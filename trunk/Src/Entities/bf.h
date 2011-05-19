#ifndef BF_H
#define BF_H

#include "../Libs/ents.h"
#include "defBF.h"
#include <Box2D/Box2D.h>
#include "../Libs/timer.h"
#include "ScrObj.h"
#include "../Libs/RandomVal.h"
#include "defCells.h"
#include "cells.h"
#include "DataDefs.h"

class bf:public Ents
{

public:
	b2World* world;
	ScrObj* itr,*head,*SOselected;

	DataDefs TCells;

	void initialize();
	void initialize(defBF *ref);
	void update();

	bf();
	void Draw(CL_GraphicContext &gc);
	void DrawEdgy(CL_GraphicContext *gc,b2Body *bodyref);
	void DrawObjs(CL_GraphicContext *gc,b2Body* bodyref);
	void checkalive();
	~bf();
	void launchWC(b2Vec2 dir);
	void intrudersGeneration();
	void launchTC(b2Vec2 dir);
	//	void DataSynchronize(defBF*ref);
	// 	int intruders;
// 	int celldeployed;
// 	int celllaunched;
// 	int cannons;

	Timer* checkTimer;
	defBF *datas;

protected:
private:
	
};
#endif