#include "app.h"
#include "../libs/querryback.h"
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
	
}



void T_App::onMouseDown(const CL_InputEvent &, const CL_InputState &)
{
	switch(global_state)
	{
	case STRATGY:
		ScrObj*temp=entites->ScrObjTraversal();
		if (temp!=NULL)
		{
			StateSwitching(TATICAL);
		}
		break;
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
		mpComWindow->set_visible(false);
		break;
	}

	global_state=newstate;
	
	switch(global_state)
	{
	case TATICAL:
		break;
	}
}