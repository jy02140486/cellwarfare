#ifndef BF_H
#define BF_H

#include "../Libs/ents.h"
#include "../Libs/IDraw.h"

class bf:public Ents,public Idraw
{
public:
	
protected:
private:
	void initalize();
	void update();
	void draw(CL_GraphicContext *gc,float x,float y);
};
#endif