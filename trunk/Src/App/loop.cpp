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
	if (!entites->updateall(global_state))
	{
		mQuit=true;
	}
	
}