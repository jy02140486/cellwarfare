#ifndef DESTRUCTIONLISTENER_H
#define DESTRUCTIONLISTENER_H

#include <box2d/Box2D.h>
class DestructionListener :public b2ContactListener
{
public:
	void EndContact(b2Contact* contact);
};

#endif