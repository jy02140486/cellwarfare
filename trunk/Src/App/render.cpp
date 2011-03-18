#include "app.h"

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);

	if (entites->curLV!=NULL)
	{
		infos->draw_text(mpComWindow->get_gc(),80,200,CL_StringRef(entites->curLV->lvdes->c_str()));
	}else CL_Console::write_line("crap");

	mpWinManager->draw_windows(mpDisplayWindow->get_gc());
		
	mpDisplayWindow->flip();
}
