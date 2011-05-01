#include "DestructionListener.h"
#include <ClanLib/core.h>

void DestructionListener::EndContact(b2Contact* contact)
{
	b2Body*body=contact->GetFixtureA()->GetBody();
	b2Body*bb=contact->GetFixtureB()->GetBody();

	body->SetUserData(NULL);

	b2World*world=body->GetWorld();

	CL_Console::write_line("abc");
}