#include "app.h"
#include "time.h"

void T_App::loop()
{
   
	time_t Btime;

	time(&Btime);
	
	tlv->Step(1.0f/60.0f,10,6);

	//CL_Console::write_line("%1",tcell->self->GetPosition().x);

	if (Btime-Atime>1/33)
	{
		double i=Btime-Atime;

		
		time(&Atime);	
		CL_KeepAlive::process();
	}
}
