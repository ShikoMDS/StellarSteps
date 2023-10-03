#pragma once

#include "SFML/Graphics.hpp"

enum CharacterType
{
	// Static Characters
	CharTypeWall, // Blocks movement
	CharTypeTrap, // Trap damages the player
	CharTypeWin, // Win tile

	// Dynamic Characters
	CharTypePlayer,
	CharTypeEnemy

};


class Character
{
public:
	// Functions ----------------------------------------------------------------------------------------- //

	// Initialise
	Character();
	~Character();

	void setCharType(CharacterType Type);

	void setSprite(sf::String Path);

	// Draw
	sf::Sprite draw();

	// Movement
	void applyGravity(float Grav, float Dt) { MCharacterYVelocity += Grav * Dt; }
	void update(float Dt, std::vector<Character*> CollisionObjects);

	// Physics 
	void setDynamic(bool Enabled) { MCharacterIsDynamic = Enabled; }

	// Repositions
	void setPosition(sf::Vector2f Pos) { MCharacterSprite.setPosition(Pos); MCharacterPosition = Pos; }

	// Collision
	void processXCollisions(Character* ObjA, Character* ObjB);
	void processYCollisions(Character* ObjA, Character* ObjB);

	void collisionParse(CharacterType Type);

	void setWindowRef(sf::RenderWindow* Window) { MWindowRef = Window; }

	// Functions ----------------------------------------------------------------------------------------- //




	// Variables ---------------------------------- //
	sf::String MCharacterName = "Base Character";
	CharacterType MCharType;

	// Visual elements
	sf::Sprite MCharacterSprite;
	sf::Texture MCharacterTexture;

	// Movement elements
	sf::Vector2f MCharacterPosition;
	sf::Vector2f MCharacterVelocity;
	float MCharacterSpeedScalar = 30.0f;


	// Gravity variable
	float MCharacterYVelocity = 0.0f;

	// Collision variables
	bool MCharacterColliding = false;
	bool MCharacterIsDynamic = true;

	// Window Reference
	sf::RenderWindow* MWindowRef{};

	// Variables ---------------------------------- //


};

