#include "app.h"

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);

	mpWinManager->draw_windows(mpDisplayWindow->get_gc());
	
	tc->draw(&mpDisplayWindow->get_gc(),mMouse.get_x(),mMouse.get_y());
	
/*
	CL_Draw::circle(mpDisplayWindow->get_gc(),
		mMouse.get_x(),
		mMouse.get_y(),
		4,
		CL_Colorf::burlywood);*/


	mpDisplayWindow->flip();
}
