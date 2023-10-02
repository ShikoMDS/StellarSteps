#include "Physics.h"

Physics::Physics()
{

}

Physics::~Physics()
{

}

void Physics::updateForces(float Dt, bool Enabled)
{
	if (Enabled)
	{
		for (int I = 0; I < MCollisionObjects.size(); I++)
		{
			if (MCollisionObjects[I]->MCharacterIsDynamic)
			{
				if (MCollisionObjects[I]->MCharacterYVelocity < 5.0f)
				{
					MCollisionObjects[I]->applyGravity(MGravityValue, Dt);
				}

				MCollisionObjects[I]->MCharacterSprite.move(0, MCollisionObjects[I]->MCharacterYVelocity);
			}
		}
	}
}

void Physics::processCollisions(float Dt, std::vector<Character*> Collisions)
{
	for (int I = 0; I < Collisions.size(); I++)
	{
		Collisions[I]->update(Dt, Collisions);
	}
}
