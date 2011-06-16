#include "DestructionListener.h"
#include <ClanLib/core.h>
#include "../Entities/cells.h"
#include "../Libs/RandomVal.h"

void DestructionListener::BeginContact(b2Contact* contact)
{
	b2Body*bodyA=contact->GetFixtureA()->GetBody();
	b2Body*bodyB=contact->GetFixtureB()->GetBody();

	if (bodyA->GetType()!=b2_dynamicBody||bodyB->GetType()!=b2_dynamicBody)
	{
		return;
	}

	cells *tc=(cells*)bodyA->GetUserData();	
	cells *tc2=(cells*)bodyB->GetUserData();

	if (tc->faction==tc2->faction)
	{
		return;
	}

	if (tc->faction==0)
	{
		tc->ContactProcess(tc2);
		return;
	}

	if (tc2->faction==0)
	{
		tc2->ContactProcess(tc);
	}
}