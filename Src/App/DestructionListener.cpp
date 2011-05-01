#include "DestructionListener.h"
#include <ClanLib/core.h>
#include "../Entities/cells.h"

void DestructionListener::EndContact(b2Contact* contact)
{
	b2Body*body=contact->GetFixtureA()->GetBody();
	b2Body*bb=contact->GetFixtureB()->GetBody();

	cells *tc=(cells*)body->GetUserData();
	tc->living=false;
	tc=(cells*)bb->GetUserData();
	tc->living=false;
	CL_Console::write_line("abc");
}