#ifndef BF_H
#define BF_H

#include "../Libs/ents.h"
#include "../Libs/IDraw.h"
#include "defBF.h"

class bf:public Ents,public Idraw
{
public:
	void initalize();
	void initalize(defBF *ref);
	void update();
	void draw(CL_GraphicContext *gc,float x,float y);

	int intruders;
	int celldeployed;

protected:
private:
	
};
#endif