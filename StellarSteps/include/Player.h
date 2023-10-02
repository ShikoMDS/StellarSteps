#pragma once

#include "Character.h"

class Player : Character
{
public:
	Player();
	~Player();

	void input(float Dt);
	void update(float Dt, std::vector<Character*> CollisionObjects);
	void setWindowRef(sf::RenderWindow* Window) { Character::setWindowRef(Window); }

	sf::Sprite draw();

};
