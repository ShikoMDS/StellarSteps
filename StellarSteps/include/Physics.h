#pragma once

#include "Player.h"

class Physics
{
public:
	float MGravityValue = 9.81f; // Positive
	std::vector<Character*> MCollisionObjects; // All objects in scene - both dynamic and static
	// std::vector<Character*> MDynamicObjects; // All dynamic objects in scene

	Physics();
	~Physics();

	void addObject(Character* Char) { MCollisionObjects.push_back(Char); }
	void updateForces(float Dt, bool Enabled);
	void processCollisions(float Dt, std::vector<Character*> Collisions);

};

