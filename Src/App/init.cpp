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
	mpComWindow->set_draggable(false);

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

	//init menu items
	mx=new CL_LineEdit(mpComWindow);
	mx->set_geometry(CL_Rect(40,40, CL_Size(80, 20)));

	my=new CL_LineEdit(mpComWindow);
	my->set_geometry(CL_Rect(40,80, CL_Size(80, 20)));

	cirfirm=new CL_PushButton(mpComWindow);
	cirfirm->set_text("enter");
	cirfirm->set_geometry(CL_Rect(40,480, CL_Size(150, 30)));
	cirfirm->func_clicked().set(this,&T_App::ButtonClick);

	CL_Point lboffset(10,10);
	CL_Size sspin(80,20);
	CL_Size slb(80,20);
	infoBF=new CL_Label(mpComWindow);
	infoBF->set_geometry(CL_Rect(10,110, CL_Size(290, 300)));
	infoBF->set_text("infobf");
	
	lbcellsdeployed=new CL_Label(infoBF);
	lbcellsdeployed->set_geometry(CL_Rect(lboffset.x,lboffset.y+5, slb));
	lbcellsdeployed->set_text("Cells deployed");
	cellsdeployed=new CL_Spin(infoBF);
	cellsdeployed->set_geometry(CL_Rect(lboffset.x+80,lboffset.y, sspin));
	cellsdeployed->set_step_size(1);
	cellsdeployed->set_ranges(0,100);
	cellsdeployed->set_value(entites->curLV->defbfs[0].ImmunityPoints);

	lbintruders=new CL_Label(infoBF);
	lbintruders->set_geometry(CL_Rect(lboffset.x,lboffset.y+35, slb));
	lbintruders->set_text("Intruders");
	intruders=new CL_Spin(infoBF);
	intruders->set_geometry(CL_Rect(lboffset.x+80,lboffset.y+30, sspin));

	lbtimeleft=new CL_Label(infoBF);
	lbtimeleft->set_geometry(CL_Rect(lboffset.x,lboffset.y+65, slb));
	lbtimeleft->set_text("Time left");
	timeleft=new CL_ProgressBar(infoBF);
	timeleft->set_geometry(CL_Rect(lboffset.x+80,lboffset.y+65, slb));
	timeleft->set_min(0);
	timeleft->set_max(100);
	timeleft->set_position(20);

	SendingCirfirm=new CL_PushButton(infoBF);
	SendingCirfirm->set_geometry(CL_Rect(lboffset.x,lboffset.y+95, slb));
	SendingCirfirm->set_text("Send");
	SendingCirfirm->func_clicked().set(this,&T_App::OnSendingCirfirmClick);

	//tatical layer
	TaticalBoard=new CL_Label(mpComWindow);
	TaticalBoard->set_geometry(CL_Rect(10,110, CL_Size(290, 300)));
	TaticalBoard->set_text("TaticalBoard");
	TaticalBoard->set_visible(false);

	lbTcellsdeployed=new CL_Label(TaticalBoard);
	lbTcellsdeployed->set_geometry(CL_Rect(lboffset.x,lboffset.y+5, slb));
	lbTcellsdeployed->set_text("Cells deployed");
	lbTcellsdeployed->set_visible(true);

	Tcellsdeployed=new CL_Label(TaticalBoard);
	Tcellsdeployed->set_geometry(CL_Rect(lboffset.x+100,lboffset.y+5, slb));
	Tcellsdeployed->set_text("Cells deployed");
	Tcellsdeployed->set_visible(true);

	lbTintruders=new CL_Label(TaticalBoard);
	lbTintruders->set_geometry(CL_Rect(lboffset.x,lboffset.y+15, slb));
	lbTintruders->set_text("Itruders");
	lbTintruders->set_visible(true);

	Tintruders=new CL_Label(TaticalBoard);
	Tintruders->set_geometry(CL_Rect(lboffset.x+100,lboffset.y+15, slb));
	Tintruders->set_text("Itruders");
	Tintruders->set_visible(true);

	entites->hero->eventTimer->func_expired().set(this,&T_App::invading_LogicLayer_Failure);
	entites->hero->eventTimer->begin(true);
	

	//LibDebugOnConsole();
	

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

void T_App::OnSendingCirfirmClick()
{
	if (entites->SOselected!=NULL)
	{
		entites->SOselected->datas->ImmunityPoints+=cellsdeployed->get_value();
		entites->hero->ImmunityPoints->val=entites->hero->ImmunityPoints->val-cellsdeployed->get_value();
	}
}