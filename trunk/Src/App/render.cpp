#include "app.h"
#include <stdio.h>

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);
	
	switch(global_state)
	{
		case STRATGY:
			body->draw(mpDisplayWindow->get_gc(), 300.0f, 0.0f);
			
		break;

		case TATICAL:
			entites->curBF->Draw(mpDisplayWindow->get_gc());

			break;
	}
	renderScrObj();
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
				
				sprintf(temp,"%d",entites->hero->HP->val);
				str=temp;
				words->draw_text(mpComWindow->get_gc(),offset.x,offset.y+40,"HP",CL_Colorf::yellow);
				words->draw_text(mpComWindow->get_gc(),offset.x+40,offset.y+40,str,CL_Colorf::yellow);
				
				sprintf(temp,"%d",entites->hero->painkiller->val);
				str=temp;
				words->draw_text(mpComWindow->get_gc(),offset.x,offset.y+60,"Pills",CL_Colorf::yellow);
				words->draw_text(mpComWindow->get_gc(),offset.x+40,offset.y+60,str,CL_Colorf::yellow);

				sprintf(temp,"%d",entites->hero->ImmunityPoints->val);
				str=temp;
				words->draw_text(mpComWindow->get_gc(),offset.x,offset.y+80,"ImmunityPoints",CL_Colorf::yellow);
				words->draw_text(mpComWindow->get_gc(),offset.x+140,offset.y+80,str,CL_Colorf::yellow);
				//delete temp;
		}
		break;

	case LVSWITCHING:
		words->draw_text(mpComWindow->get_gc(),offset.x,offset.y+20,"times up");
		break;

	case TATICAL:
		
		words->draw_text(mpComWindow->get_gc(),310,20,CL_StringRef (entites->SOselected->des->data()));
		char *temp=new char(10);
		sprintf(temp,"%d",entites->SOselected->datas->ImmunityPoints);
		CL_StringRef str=temp;
		words->draw_text(mpComWindow->get_gc(),380,20,str);
	}
}

void T_App::renderScrObj()
{
	switch(global_state)
	{
	case STRATGY:
		for (entites->itr=entites->head;entites->itr!=NULL;entites->itr=entites->itr->next)
			entites->itr->draw(&mpDisplayWindow->get_gc());
		break;
	case TATICAL:
		for (entites->curBF->itr=entites->curBF->head;entites->curBF->itr!=NULL;entites->curBF->itr=entites->curBF->itr->next)
			entites->curBF->itr->draw(&mpDisplayWindow->get_gc());
	}

/*	head->draw(&mpDisplayWindow->get_gc());*/

}