#include "app.h"
#include "time.h"

void T_App::loop()
{
   
	time_t Btime;

	time(&Btime);	

	if (Btime-Atime>1/33)
	{
		double i=Btime-Atime;
		time(&Atime);	
		CL_KeepAlive::process();
	}

	entites->posMouse=mMouse.get_position();
//  	if(entites->SOselected!=NULL)
// // 	if (entites->SOselected->ObjState==ScrObj::NORMAL)
// 	{
// 		CL_Console::write_line("aaa");
// 	}

//	
	if (global_state==LVSWITCHING)
	{
		cellsdeployed->set_value(entites->curLV->defbfs[0].celldeployed);
	}

	if (global_state==TATICAL)
	{
		updateBoard();
	}

	if (!entites->updateall(global_state))
	{
		
		mQuit=true;
	}
	
}
