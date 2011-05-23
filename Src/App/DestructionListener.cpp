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

// 	int dice=RandomVal::int_from_to(1,100);
// 	switch(tc->cell_type)
// 	{
// 	case cells::WC:
// 		if (tc2->cell_type==cells::NAKED)
// 			if(dice>50)
// 			{
// 				tc->waste();
// 				tc2->waste();
// 				break;
// 			}
// 		if (tc2->cell_type==cells::ARMORED)
// 			if(dice>50)
// 				tc->waste();
// 					
// 		tc2->cell_type=cells::NAKED;
// 				
// 		break;
// 
// 	case cells::TC:
// 		if (tc2->cell_type==cells::NAKED)
// 			if(dice>50)
// 			{
// 				tc->waste();
// 				tc2->waste();
// 			}
// 		break;
// 	case cells::ARMORED:
// 		break;
// 	case cells::NAKED:
// 		break;
//	}
// 	CL_Console::write_line("%1 celllaunched left",tc->belong->celllaunched);
// 	CL_Console::write_line("%1 cellsdeployed left",tc->belong->celldeployed);
// 	CL_Console::write_line("%1 intruders left",tc->belong->intruder);

// 	if (tc->faction!=tc2->faction)
// 	{
// 		tc->living=false;
// 
// 		tc2->living=false;
// 	}
}