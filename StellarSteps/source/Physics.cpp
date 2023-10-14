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
		for (auto& MCollisionObject : MCollisionObjects)
		{
			if (MCollisionObject->MCharacterIsDynamic)
			{
				if (MCollisionObject->MCharacterYVelocity < 5.0f)
				{
					MCollisionObject->applyGravity(MGravityValue, Dt);
				}

				//MCollisionObject->MCharacterSprite.move(0, MCollisionObject->MCharacterYVelocity);
			}
		}
	}
}

void Physics::processCollisions(float Dt, std::vector<Character*> Collisions)
{
	for (int I = 0; I < static_cast<int>(Collisions.size()); I++)
	{
		Collisions[I]->update(Dt, Collisions);
	}
}
