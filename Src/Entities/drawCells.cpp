#include "drawCells.h"

void drawCells::draw(CL_GraphicContext *gc ,float x,float y)
{
	CL_Draw::circle(*gc,
		x,
		y,
		4,
		CL_Colorf::blueviolet);
}

drawCells::drawCells()
{

}