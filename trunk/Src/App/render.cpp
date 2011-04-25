#include "app.h"
#include <stdio.h>

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);
	
	switch(global_state)
	{
		case STRATGY:
			body->draw(mpDisplayWindow->get_gc(), 300.0f, 0.0f);
			renderScrObj();
		break;

		case TATICAL:
			entites->curBF->Draw(mpDisplayWindow->get_gc());

			break;
	}
	
	renderdes();

	mpWinManager->draw_windows(mpDisplayWindow->get_gc());
		
	mpDisplayWindow->flip();
	
}


void T_App::renderdes()
{
	
	switch(global_state)
	{
	case STRATGY:
		if (entites->curLV!=NULL)
		{
			words->draw_text(mpComWindow->get_gc(),offset.x,offset.y,CL_StringRef(*entites->curLV->lvdes),CL_Colorf::yellow);
				

				char *temp=new char(10);
				sprintf(temp,"%d",entites->curLV->lvtimer->get_curSec());
				CL_StringRef str=temp;

				words->draw_text(mpComWindow->get_gc(),offset.x,offset.y+20,str,CL_Colorf::yellow);
				//delete temp;
		}
		break;

	case LVSWITCHING:
		words->draw_text(mpComWindow->get_gc(),offset.x,offset.y+20,"times up");
		break;

	case TATICAL:
		words->draw_text(mpComWindow->get_gc(),310,20,CL_StringRef (entites->SOselected->des->data()));
	}
}

void T_App::renderScrObj()
{
	for (entites->itr=entites->head;entites->itr!=NULL;entites->itr=entites->itr->next)
	{
		entites->itr->draw(&mpDisplayWindow->get_gc());
	}
/*	head->draw(&mpDisplayWindow->get_gc());*/

}