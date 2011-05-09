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
	cells*tc2=(cells*)bb->GetUserData();
// 	CL_Console::write_line("%1 celllaunched left",tc->belong->celllaunched);
// 	CL_Console::write_line("%1 cellsdeployed left",tc->belong->celldeployed);
// 	CL_Console::write_line("%1 intruders left",tc->belong->intruder);

	if (tc->faction!=tc2->faction)
	{
		tc->living=false;

		tc2->living=false;
	}

}