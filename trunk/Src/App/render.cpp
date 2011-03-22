#include "app.h"
#include <stdio.h>

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);


	if (entites->curLV!=NULL)
	{
		entites->lvdes->draw_text(mpComWindow->get_gc(),CL_Pointf(400,400),CL_StringRef(*entites->curLV->lvdes),CL_Colorf::yellow);
	
		char *temp=new char(10);
		sprintf(temp,"%d",entites->curLV->lvtimer->get_curSec());
		CL_StringRef str=temp;

		CL_Console
			::write_line("start flag %1,current %2,timer %3 ",entites->curLV->lvtimer->startflag,CL_System::get_time(),entites->curLV->lvtimer->get_curSec());
		
		entites->lvdes->draw_text(mpComWindow->get_gc(),CL_Pointf(400,420),str,CL_Colorf::yellow);
	}



	mpWinManager->draw_windows(mpDisplayWindow->get_gc());
		
	mpDisplayWindow->flip();
}
