#include "app.h"
#include "event.h"
#include <time.h>

bool T_App::init()
{
	try
	{
	
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

	//initail GUIComponet window
	CL_DisplayWindowDescription comWindowDesc;
	comWindowDesc.show_border(false);
	comWindowDesc.set_allow_resize(true);
	comWindowDesc.set_title("settings");
	comWindowDesc.set_size(CL_Size(300, 570),false);
	comWindowDesc.set_allow_resize(true);
	comWindowDesc.set_layered(true);

	mpComWindow = new CL_Window(&mGui, comWindowDesc);
	mpComWindow->set_draggable(true);

	//initail events
	mInput = mpDisplayWindow->get_ic();
	mKeyboard = mInput.get_keyboard();
	mMouse = mInput.get_mouse();
	//mJoystick = mInput.get_joystick();


	mpConsole = new CL_ConsoleWindow("Console", 80, 100);


	entites=new EM();
	entites->iniLVs();
	words=new CL_Font(mpComWindow->get_gc(),"Tahoma",20);
	offset.x=320;
	offset.y=420;
	entites->initScrObjs();

	body=new CL_Image(mpDisplayWindow->get_gc(),"../res/body.png");

	mx=new CL_LineEdit(mpComWindow);
	mx->set_geometry(CL_Rect(40,40, CL_Size(80, 20)));

	my=new CL_LineEdit(mpComWindow);
	my->set_geometry(CL_Rect(40,80, CL_Size(80, 20)));

	cirfirm=new CL_PushButton(mpComWindow);
	cirfirm->set_text("enter");
	cirfirm->set_geometry(CL_Rect(40,480, CL_Size(100, 30)));
	cirfirm->func_clicked().set(this,&T_App::ButtonClick);
	
	LibDebugOnConsole();
	

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


