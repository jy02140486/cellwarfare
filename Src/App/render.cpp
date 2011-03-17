#include "app.h"

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);

	mpWinManager->draw_windows(mpDisplayWindow->get_gc());

	tcell->draw(&mpDisplayWindow->get_gc(),tcell->self->GetPosition().x,tcell->self->GetPosition().y);
	
//	tlv->lvdes->draw_text(mpDisplayWindow->get_gc(),80,80,"stage11111111111111111111",CL_Colorf::yellow);
		
	mpDisplayWindow->flip();
}
