#include "app.h"
#include <stdio.h>

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);

	renderdes();

	mpWinManager->draw_windows(mpDisplayWindow->get_gc());
		
	mpDisplayWindow->flip();
}


void T_App::renderdes()
{
	if (entites->curLV!=NULL)
	{
		entites->lvdes->draw_text(mpComWindow->get_gc(),CL_Pointf(400,400),CL_StringRef(*entites->curLV->lvdes),CL_Colorf::yellow);

		if (entites->curLV->lvtimer->get_curSec()==-1)
		{
		
			entites->lvdes->draw_text(mpComWindow->get_gc(),CL_Pointf(400,420),"times up");
		} 
		else
		{
			char *temp=new char(10);
			sprintf(temp,"%d",entites->curLV->lvtimer->get_curSec());
			CL_StringRef str=temp;

			entites->lvdes->draw_text(mpComWindow->get_gc(),CL_Pointf(400,420),str,CL_Colorf::yellow);
			//delete temp;
		}
	}
}