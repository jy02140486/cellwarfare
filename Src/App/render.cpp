#include "app.h"

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);

	mpWinManager->draw_windows(mpDisplayWindow->get_gc());

	tcell->draw(&mpDisplayWindow->get_gc(),tcell->self->GetPosition().x,tcell->self->GetPosition().y);
		
	mpDisplayWindow->flip();
}
