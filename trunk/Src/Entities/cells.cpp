#include "cells.h"
#include "../Libs/RandomVal.h"

void cells::initialize()
{
	_ImpDraw=new drawCells();
}

void cells::initialize(b2BodyDef *odef,b2World *world)
{
	_ImpDraw=new drawCells();
	self=(b2Body*)world->CreateBody(odef);
	self->SetUserData(this);
	b2Fixture *temp=self->CreateFixture(&shape,1);
	temp->SetRestitution(6.0);
	faction=0;
	living=true;
}

void cells::initialize(b2World *world)
{
	_ImpDraw=new drawCells();
	self=(b2Body*)world->CreateBody(&def);
	self->SetUserData(this);
	b2Fixture *temp=self->CreateFixture(&shape,1);
	temp->SetRestitution(6.0);
	faction=0;
	living=true;
}

//0 good;1 bad
void cells::initialize(b2World *world,int faction)
{
	_ImpDraw=new drawCells();
	self=(b2Body*)world->CreateBody(&def);
	self->SetUserData(this);
	b2Fixture *temp=self->CreateFixture(&shape,1);
	temp->SetRestitution(6.0);
	this->faction=faction;
	living=true;
}

// void cells::launch(b2World*world,b2Vec2 dir)
// {
// 	_ImpDraw=new drawCells();
// 	b2BodyDef tempdef=def;
// 	tempdef.position=
// 	self=(b2Body*)world->CreateBody(&def);
// 	self->SetUserData(this);
// 	self->CreateFixture(&shape,1);
// 	this->faction=faction;
// 	living=true;
// }


void cells::update()
{

}

void cells::draw(CL_GraphicContext *gc,float x,float y)
{
	_ImpDraw->draw(gc,x,y,self->GetFixtureList()->GetShape()->m_radius);
}

cells::cells()
{
	def.type=b2_dynamicBody;
	b2Vec2 temp;
	CL_Point cltemp;
	cltemp=*RandomVal::randomPointi(320,50,770,450);
	temp.x=cltemp.x;
	temp.y=cltemp.y;
// 	temp.x=400;
// 	temp.y=400;
	def.position=temp;
	def.allowSleep=true;
	def.linearVelocity=b2Vec2(RandomVal::int_from_to(0,90),RandomVal::int_from_to(0,90));
	
	shape.m_radius=10;
}

void cells::Draw(CL_GraphicContext *gc)
{
	// 	CL_Gradient color2(CL_Colorf::burlywood, CL_Colorf::honeydew);

// 	CL_Draw::circle(*gc,
// 		self->GetPosition().x,
// 		self->GetPosition().y,
// 		self->GetFixtureList()->GetShape()->m_radius,
// 		CL_Colorf::blueviolet);

	switch(faction)
	{
	case 0:
		CL_Draw::circle(*gc,
			self->GetPosition().x,
			self->GetPosition().y,
			self->GetFixtureList()->GetShape()->m_radius,
			CL_Colorf::white);
		break;
	case 1:
		CL_Draw::circle(*gc,
			self->GetPosition().x,
			self->GetPosition().y,
			self->GetFixtureList()->GetShape()->m_radius,
			CL_Colorf::blueviolet);
		break;
	}
}
