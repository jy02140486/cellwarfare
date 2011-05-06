#include "DestructionListener.h"
#include <ClanLib/core.h>
#include "../Entities/cells.h"

void DestructionListener::BeginContact(b2Contact* contact)
{
	b2Body*body=contact->GetFixtureA()->GetBody();
	b2Body*bb=contact->GetFixtureB()->GetBody();

	if (body->GetType()!=b2_dynamicBody||bb->GetType()!=b2_dynamicBody)
	{
		return;
	}

	cells *tc=(cells*)body->GetUserData();
	tc->living=false;
	tc=(cells*)bb->GetUserData();
	tc->living=false;
	CL_Console::write_line("%1 bodys left",bb->GetWorld()->GetBodyCount());
}