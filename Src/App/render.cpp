#include "app.h"

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);

	mpWinManager->draw_windows(mpDisplayWindow->get_gc());
		



	
	mpDisplayWindow->flip();
}
