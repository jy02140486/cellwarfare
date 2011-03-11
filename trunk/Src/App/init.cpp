#include "app.h"
#include "event.h"
#include <time.h>

bool T_App::init()
{
	try
	{
	tlv=new levels();
	
	b2BodyDef bodyDef;

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(180.0f, 40.0f);

	bodyDef.allowSleep=false;

	b2Body *tbody=(b2Body*)tlv->CreateBody(&bodyDef);
	
	b2CircleShape tshape;
	tshape.m_radius=8.0f;

	tbody->CreateFixture(&tshape,2.0f);


	//initail window description
	mWinDesc.set_title("CellWarfare");
	mWinDesc.set_allow_resize(true);
	mWinDesc.set_size(CL_Size (800, 600), false);

	
	CL_String resource("../Res/GUITheme/resources.xml");
	CL_String theme("../Res/GUITheme/theme.css");

	//initail resource manager
	mResManager.load(resource);

	////initail gui theme
	mGUITheme.set_resources(mResManager);

	//initail gui
	mpDisplayWindow = new CL_DisplayWindow(mWinDesc);
	mpWinManager = new CL_GUIWindowManagerTexture(*mpDisplayWindow);
	mGui.set_window_manager(*mpWinManager);
	mGui.set_theme(mGUITheme);
	mGui.set_css_document(theme);

	mpWinManager->func_repaint().set(this, &T_App::render);


	//initail events
	mInput = mpDisplayWindow->get_ic();
	mKeyboard = mInput.get_keyboard();
	mMouse = mInput.get_mouse();
	//mJoystick = mInput.get_joystick();

	mpConsole = new CL_ConsoleWindow("Console", 80, 100);
	
	time(&Atime);
	}
	catch (CL_Exception &exception)
	{
		CL_Console::write_line("Exception:Init error",
			exception.get_message_and_stack_trace());
// 		mpConsole->display_close_message();
		CL_Console::write_line(exception.get_message_and_stack_trace());

		return true;
	}

	running=true;

	T_Event::eventInit();
	T_App::eventInit();

// 	slotMouseDown = mMouse.sig_key_down().connect(this,
// 		&T_App::onMouseDown);

	return true;
}

