#include "cells.h"
#include "../Libs/RandomVal.h"

void cells::initialize()
{
}


void cells::update()
{

}

void cells::waste()
{
	living=false;
}
void cells::initialize(defCells* refTemplateC,b2World *world,defBF*refbelong)
{
	refTemplateC->def.position;
	self=world->CreateBody(&refTemplateC->def);
	self->SetUserData(this);
	living=refTemplateC->living;
	faction=refTemplateC->faction;
	reflectR=refTemplateC->reflectR;

	switch(refTemplateC->cell_type)
	{
	case WC:
		cell_type=WC;
		break;
	case TC:
		cell_type=TC;
		break;
	case ARMORED:
		cell_type=ARMORED;
		break;
	case NAKED:
		cell_type=NAKED;
		break;
	}
	
	belong=refbelong;
	self->CreateFixture(&refTemplateC->shape,1);
}

cells::cells()
{
	b2Vec2 temp;
	CL_Point cltemp;
	cltemp=*RandomVal::randomPointi(320,50,770,450);
	temp.x=cltemp.x;
	temp.y=cltemp.y;
// 	temp.x=400;
// 	temp.y=400;
}

void cells::Draw(CL_GraphicContext *gc)
{
	// 	CL_Gradient color2(CL_Colorf::burlywood, CL_Colorf::honeydew);

// 	CL_Draw::circle(*gc,
// 		self->GetPosition().x,
// 		self->GetPosition().y,
// 		self->GetFixtureList()->GetShape()->m_radius,
// 		CL_Colorf::blueviolet);

// 	switch(faction)
// 	{
// 	case 0:
// 		CL_Draw::circle(*gc,
// 			self->GetPosition().x,
// 			self->GetPosition().y,
// 			self->GetFixtureList()->GetShape()->m_radius,
// 			CL_Colorf::white);
// 		break;
// 	case 1:
// 		CL_Draw::circle(*gc,
// 			self->GetPosition().x,
// 			self->GetPosition().y,
// 			self->GetFixtureList()->GetShape()->m_radius,
// 			CL_Colorf::blueviolet);
// 		break;
// 	}


	switch(cell_type)
	{
	case WC:
		CL_Draw::circle(*gc,
			self->GetPosition().x,
			self->GetPosition().y,
			self->GetFixtureList()->GetShape()->m_radius,
			CL_Colorf::white);
		break;
	case ARMORED:
		CL_Draw::circle(*gc,
			self->GetPosition().x,
			self->GetPosition().y,
			self->GetFixtureList()->GetShape()->m_radius,
			CL_Colorf(255.0f,255.0f,0.0f,0.4f));
	
	case NAKED:
		CL_Draw::circle(*gc,
			self->GetPosition().x,
			self->GetPosition().y,
			self->GetFixtureList()->GetShape()->m_radius,
			CL_Colorf::blueviolet);
		break;
	
	case TC:
		CL_Draw::circle(*gc,
			self->GetPosition().x,
			self->GetPosition().y,
			self->GetFixtureList()->GetShape()->m_radius,
			CL_Colorf::burlywood);
		break;
	}

}