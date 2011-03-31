#include "app.h"
#include <stdio.h>

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);

	renderdes();

	body->draw(mpDisplayWindow->get_gc(), 300.0f, 0.0f);


	mpWinManager->draw_windows(mpDisplayWindow->get_gc());
		
	mpDisplayWindow->flip();
}


void T_App::renderdes()
{
	if (entites->curLV!=NULL)
	{
		words->draw_text(mpComWindow->get_gc(),offset.x,offset.y,CL_StringRef(*entites->curLV->lvdes),CL_Colorf::yellow);

		if (entites->curLV->lvtimer->get_curSec()==-1)
		{
		
			words->draw_text(mpComWindow->get_gc(),offset.x,offset.y+20,"times up");
		} 
		else
		{
			char *temp=new char(10);
			sprintf(temp,"%d",entites->curLV->lvtimer->get_curSec());
			CL_StringRef str=temp;

			words->draw_text(mpComWindow->get_gc(),offset.x,offset.y+20,str,CL_Colorf::yellow);
			//delete temp;
		}
	}
}