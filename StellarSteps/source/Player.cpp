#include "Player.h"

Player::Player()
{
	setSprite("Images/Sprites/PlayerBlock.bmp");
	MCharacterSprite.setOrigin(MCharacterTexture.getSize().x / 2, MCharacterTexture.getSize().y / 2);
	MCharacterPosition = sf::Vector2f(400, 250);
	MCharacterSprite.setPosition(MCharacterPosition);

	MCharacterName = "Player";
}

Player::~Player()
{

}

void Player::input(float Dt)
{
	MCharacterVelocity = sf::Vector2f(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		MCharacterVelocity.y = -5;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		MCharacterVelocity.y = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		MCharacterVelocity.x = -2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		MCharacterVelocity.x = 2;
	}
}

void Player::update(float Dt, std::vector<Character*> CollisionObjects)
{
	return Character::update(Dt, CollisionObjects);
}

sf::Sprite Player::draw()
{
	return Character::draw();
}
