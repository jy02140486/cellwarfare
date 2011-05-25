#include "app.h"
#include "../libs/querryback.h"
#include "../Libs/Converter.h"
#include <time.h>

#define FPS 44

T_App::T_App()
{
	/* code */
}

int T_App::start()
{
	srand (time(NULL));

	if (init() == false)
	{
		return -1;
	}

	global_state=STRATGY;

	int fps=FPS;
	mrk=GetTickCount();

	while (!mQuit)
	{
		if (GetTickCount()-mrk>1000/fps)
		{
			mGui.exec(false);
			loop();
			mrk=GetTickCount();
		}
		else Sleep(1000.0/fps-(GetTickCount()-mrk));
	}

	return 0;
}

void T_App::onMouseUp(const CL_InputEvent &, const CL_InputState &)
{
	switch(global_state)
	{
		case STRATGY:
		{	
			if (mpComWindow->get_client_area().contains(mMouse.get_position()))
			{
				return;
			}
			;
			ScrObj*temp=entites->ScrObjTraversal();
			if (temp!=NULL)
			{
			if(entites->SOselected!=NULL)
				if (intruders==0)					
					entites->SOselected->ObjState=ScrObj::NORMAL;
				else entites->SOselected->ObjState=ScrObj::INTRUDED;

				entites->SOselected=temp;
				ScrObjSelect();
			}else 
			{
				//entites->SOselected=NULL;
				infoBF->set_visible(false);
			}break;
		}

		case TATICAL:
		{

			bf* tbf=entites->curBF;
			if(tbf->SOselected==NULL||tbf->datas->ImmunityPoints<=0)
				return;

			
			CL_Vec2i cannon(tbf->SOselected->pos->x,tbf->SOselected->pos->y);
			CL_Vec2i mouse=mMouse.get_position();

			b2Vec2 b2cannon=Converter::Vec2from_c_to_b(cannon);
			b2Vec2 b2mouse=Converter::Vec2from_c_to_b(mouse);

			b2Vec2 dir=b2mouse-b2cannon;

			switch(tbf->SOselected->ObjState)
			{
			case ScrObj::LYMPH:
				tbf->launchTC(dir);
				break;
			case ScrObj::CANNON:
				tbf->launchWC(dir);
				break;
			}
			tbf->datas->ImmunityPoints--;
			tbf->SOselected=NULL;		
		}break;
	}
}



void T_App::onMouseDown(const CL_InputEvent &, const CL_InputState &)
{
	switch(global_state)
	{
	case TATICAL:
		bf* tbf=entites->curBF;
		ScrObj*temp=entites->ScrObjTraversal(tbf->head);

		if (temp!=NULL)
			tbf->SOselected=temp;
		break;
	//default:temp;
	}
}

void T_App::onMouseMove(const CL_InputEvent &, const CL_InputState &)
{
	mx->set_text(mMouse.get_x());
	my->set_text(mMouse.get_y());
}


int T_App::eventInit()
{
	//ÅäÖÃÊÂ¼þ²å²Û
	slotMouseMove = mMouse.sig_pointer_move().connect(this,
		&T_App::onMouseMove);
	slotMouseDown = mMouse.sig_key_down().connect(this,
		&T_App::onMouseDown);
	slotMouseUp=mMouse.sig_key_up().connect(this,
		&T_App::onMouseUp);
	slotKeyboardUp=mKeyboard.sig_key_up().connect(this, 
		&T_App::onKeyboardUp);

	return 0;
}

void T_App::onKeyboardUp(const CL_InputEvent &key,
						   const CL_InputState &state)
{
	
}

void T_App::StateSwitching(GLOBAL_STATE newstate)
{
	switch(global_state)
	{
	case STRATGY:
		//mpComWindow->set_visible(false);
		cirfirm->set_text("Quit");
		infoBF->set_visible(false);
		TaticalBoard->set_visible(true);
		break;

	case TATICAL:
		cirfirm->set_text("Enter");
		infoBF->set_visible(true);
//		TaticalBoard->set_visible(false);
		break;
	}

	global_state=newstate;
	
	switch(global_state)
	{
	case TATICAL:
		break;
	}
}

void T_App::ButtonClick()
{
	//
	switch(global_state)
	{
	case STRATGY:
		if (entites->SOselected!=NULL)
		{
			entites->setcurBF(entites->SOselected->datas);
			
			char *temp=new char(10);
			sprintf(temp,"%d",entites->SOselected->datas->ImmunityPoints);
			CL_StringRef str=temp;
			Tcellsdeployed->set_text(temp);

			StateSwitching(TATICAL);
		}
		break;
	case TATICAL:	
		StateSwitching(STRATGY);
//		entites->curBF->DataSynchronize(entites->SOselected->datas);
		entites->retreat();
		entites->SOselected->ObjState=ScrObj::NORMAL;
		entites->curBF->~bf();
	//	delete entites->curBF;
		break;
	default:;
	}
}

void T_App::ScrObjSelect()
{
	ScrObj*temp=entites->SOselected;
	cellsdeployed->set_value(temp->datas->ImmunityPoints);
	intruders->set_value(temp->datas->intruder);

	if (temp->timer!=NULL)
	{
	//	timeleft->set_max(temp->timer->length);
		timeleft->set_position(entites->SOselected->timer->length-entites->SOselected->timer->get_curSec());
	}
	infoBF->set_visible(true);
	char tempt[10];
	sprintf(tempt,"%d",entites->SOselected->datas->intruder);
	CL_StringRef str=tempt;
	Tintruders->set_text(tempt);
}

void T_App::invading_LogicLayer_Failure()
{
	if (global_state==STRATGY)
	{

		int i=RandomVal::int_from_to(0,3);
		int ti=RandomVal::int_from_to(1,28);
		ScrObj*temp=entites->head;
			for(int j=0;j<i;j++)
			{
				temp=temp->next;
			}
			if (temp->ObjState!=ScrObj::INTRUDED)
			{			

			entites->curLV->defbfs[i].intruder=ti;
			intruders->set_value(ti);
			temp->ObjState=ScrObj::INTRUDED;
			temp->timer=new Timer();
			Timer* tt=temp->timer;
			int ttime=ti+8;
			tt->init(ttime,false);
			temp->datas->timeleft=ttime;
			tt->begin(false);
			tt->func_expired().set(this,&T_App::Ttimesup);
	

			CL_Console::write_line("aa");
			}
	}
}

void T_App::Ttimesup()
{
	CL_Console::write_line("call");
	//entites->hero->HP->minus();
	for(ScrObj* temp=entites->head;temp!=NULL;temp=temp->next)
	{
		if(temp->timer!=NULL)
		if (temp->timer->get_curSec()<=0)
		{
			entites->hero->HP->minus(temp->datas->intruder);
			temp->ObjState=ScrObj::NORMAL;
			break;
		}
	}
}

void T_App::updateBoard()
{
	char *temp=new char(10);
	sprintf(temp,"%d",entites->SOselected->datas->ImmunityPoints);
	CL_StringRef str=temp;
	Tcellsdeployed->set_text(temp);
}