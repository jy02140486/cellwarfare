#include "app.h"
#include <stdio.h>
#include "../Libs/Converter.h"

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
		
			{
				if (entites->curBF->SOselected==NULL)
				{
					break;
				}

				CL_Vec4f red_color(1.0f, 0.0f, 0.0f, 1.0f);
				CL_Vec4f green_color(0.0f, 1.0f, 0.0f, 1.0f);
				CL_Vec4f black_color(0.0f, 0.0f,0.0f, 1.0f);

				CL_Vec2i positions[2];
				CL_Vec4f colors[] = { red_color, green_color};

				positions[0]=CL_Vec2f(entites->curBF->SOselected->pos->x,entites->curBF->SOselected->pos->y);	
				positions[1]=CL_Vec2f(mMouse.get_x(),mMouse.get_y());	

				CL_GraphicContext *tgc=&mpDisplayWindow->get_gc();
				CL_PrimitivesArray vecs(*tgc);

				vecs.set_attributes(0,positions);
				vecs.set_attributes(1,colors);

				tgc->set_program_object(cl_program_color_only);
				tgc->draw_primitives(cl_line_strip,2,vecs);

				int dice=RandomVal::int_from_to(1,100);
// 				if (dice<=30)
// 				{
// 					entites->curBF->showVD(Converter::Vec2from_c_to_b(mMouse.get_position()));
// 					tgc->draw_primitives(cl_points,1,vecs);
// 				}
			}

			break;
		case LVSWITCHING:
			stage_clear->draw(mpDisplayWindow->get_gc(), 300.0f, 0.0f);
			break;
		case GAMEOVER:
			gameover->draw(mpDisplayWindow->get_gc(), 300.0f, 0.0f);
			break;
		case ALL_CLEAR:
			all_clear->draw(mpDisplayWindow->get_gc(), 300.0f, 0.0f);
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
		words->draw_text(mpComWindow->get_gc(),offset.x,offset.y+40,"Stage Clear");
		break;

	case TATICAL:	
		{
		words->draw_text(mpComWindow->get_gc(),310,20,CL_StringRef (entites->SOselected->des->data()));
		char *temp=new char(10);
		sprintf(temp,"%d",entites->SOselected->datas->ImmunityPoints);
		CL_StringRef str=temp;
		words->draw_text(mpComWindow->get_gc(),380,20,str);
		break;
		}
	case ALL_CLEAR:
		words->draw_text(mpComWindow->get_gc(),offset.x,offset.y+20,"Congratulations!You helped Billy survive.");
		words->draw_text(mpComWindow->get_gc(),offset.x,offset.y+40,"Thanks for playing");
		break;
	case GAMEOVER:
		words->draw_text(mpComWindow->get_gc(),offset.x,offset.y+20,"Shame.Game over.Billy can't take more.");
	}
}

void T_App::renderScrObj()
{
	switch(global_state)
	{
	case STRATGY:
		for (entites->itr=entites->head;entites->itr!=NULL;entites->itr=entites->itr->next)
			entites->itr->draw(&mpDisplayWindow->get_gc());
		if (entites->SOselected!=NULL)
		{

			CL_Draw::circle(mpDisplayWindow->get_gc(),entites->SOselected->pos->x,entites->SOselected->pos->y,entites->SOselected->refradius/2,CL_Colorf::red);
		}
		break;
	case TATICAL:
		for (entites->curBF->itr=entites->curBF->head;entites->curBF->itr!=NULL;entites->curBF->itr=entites->curBF->itr->next)
			entites->curBF->itr->draw(&mpDisplayWindow->get_gc());
	}


}