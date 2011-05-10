#include "app.h"
#include "../libs/querryback.h"
#include "../Libs/Conveter.h"
#define FPS 44

T_App::T_App()
{
	/* code */
}

int T_App::start()
{
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
		case TATICAL:
		{
			bf* tbf=entites->curBF;
			if(tbf->SOselected==NULL||tbf->celldeployed<=0)
				return;

			
			CL_Vec2i cannon(tbf->SOselected->pos->x,tbf->SOselected->pos->y);
			CL_Vec2i mouse=mMouse.get_position();

			b2Vec2 b2cannon=Conveter::Vec2from_c_to_b(cannon);
			b2Vec2 b2mouse=Conveter::Vec2from_c_to_b(mouse);

			cells*temp=new cells();

			b2BodyDef tempdef;
			tempdef.type=b2_dynamicBody;
			tempdef.position=b2cannon;
			
			temp->initialize(&tempdef,tbf->world);
			temp->belong=entites->curBF->SOselected->datas;
			temp->self->SetLinearVelocity(b2mouse-b2cannon);

			tbf->celllaunched++;
			tbf->celldeployed--;
			tbf->SOselected=NULL;
		}break;
	}
}



void T_App::onMouseDown(const CL_InputEvent &, const CL_InputState &)
{
	switch(global_state)
	{
	case STRATGY:
		{
			ScrObj*temp=entites->ScrObjTraversal();
			if (temp!=NULL)
			{
				if(entites->SOselected!=NULL)
					if (intruders==0)					
					entites->SOselected->ObjState=ScrObj::NORMAL;
					else entites->SOselected->ObjState=ScrObj::INTRUDED;
			
				entites->SOselected=temp;
				entites->SOselected->ObjState=ScrObj::SELECTED;
				ScrObjSelect();
			}
		break;
		}

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
		TaticalBoard->set_visible(false);
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
			sprintf(temp,"%d",entites->SOselected->datas->celldeployed);
			CL_StringRef str=temp;
			Tcellsdeployed->set_text(temp);

			StateSwitching(TATICAL);
		}
		break;
	case TATICAL:	
		StateSwitching(STRATGY);
		entites->curBF->DataSynchronize(entites->SOselected->datas);
		entites->curBF->~bf();
	//	delete entites->curBF;
		break;
	default:;
	}
}

void T_App::ScrObjSelect()
{
	ScrObj*temp=entites->SOselected;
	cellsdeployed->set_value(temp->datas->celldeployed);
	intruders->set_value(temp->datas->intruder);
}

void T_App::invading_LogicLayer_Failure()
{
	if (global_state==STRATGY)
	{
		int i=RandomVal::int_from_to(0,3);
		int ti=RandomVal::int_from_to(1,8);
		entites->curLV->defbfs[i].intruder=ti;
		intruders->set_value(ti);

		ScrObj*temp=entites->head;
			for(int j=0;j<i;j++)
			{
				temp=temp->next;
			}
			temp->ObjState=ScrObj::INTRUDED;
			CL_Console::write_line("aa");
	}
}

void T_App::updateBoard()
{
	char *temp=new char(10);
	sprintf(temp,"%d",entites->SOselected->datas->celldeployed);
	CL_StringRef str=temp;
	Tcellsdeployed->set_text(temp);
}