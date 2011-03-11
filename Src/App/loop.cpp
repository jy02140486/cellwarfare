#include "app.h"
#include "time.h"

void T_App::loop()
{
   
	time_t Btime;

	time(&Btime);

	if (Btime-Atime>1/33)
	{
		double i=Btime-Atime;

		tlv->Step(1.0f/60.0f,10,6);
		time(&Atime);	
		CL_KeepAlive::process();
	}
}
