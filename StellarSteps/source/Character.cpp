#include "Character.h"

Character::Character()
{
	setSprite("Images/Sprites/DefaultBlock.bmp");
	//MCharacterSprite.setOrigin(MCharacterTexture.getSize().x / 2, MCharacterTexture.getSize().y / 2);
	MCharacterPosition = sf::Vector2f(400, 250);
	MCharacterSprite.setPosition(MCharacterPosition);
}

Character::~Character() = default;

void Character::setCharType(CharacterType Type)
{
	switch (Type)
	{
	case CharTypeWall:
		setSprite("Images/Sprites/DefaultBlock.bmp");
		setDynamic(false);
		break;
	case CharTypeTrap:
		setSprite("Images/Sprites/TrapBlock.bmp");
		setDynamic(false);
		break;
	case CharTypeWin:
		setSprite("Images/Sprites/WinBlock.bmp");
		setDynamic(false);
		break;
	case CharTypePlayer:
		setSprite("Images/Sprites/PlayerBlock.bmp");
		break;
	case CharTypeEnemy:
		break;
	}

	MCharType = Type;
}

void Character::setSprite(sf::String Path)
{
	MCharacterTexture.loadFromFile(Path);
	MCharacterSprite.setTexture(MCharacterTexture);
}

sf::Sprite Character::draw()
{
	return MCharacterSprite;
}

void Character::update(float Dt, std::vector<Character*> CollisionObjects)
{
	MCharacterSprite.move(0, MCharacterVelocity.y * MCharacterSpeedScalar * Dt);

	for (auto& CollisionObject : CollisionObjects)
	{
		if (MCharacterSprite.getGlobalBounds().intersects(CollisionObject->MCharacterSprite.getGlobalBounds()) &&
			MCharacterName != CollisionObject->MCharacterName)
		{
			collisionParse(CollisionObject->MCharType);
			MCharacterColliding = true;
			MCharacterYVelocity = 0;
			processYCollisions(this, CollisionObject);
		}
	}

	MCharacterSprite.move(MCharacterVelocity.x * MCharacterSpeedScalar * Dt, 0);

	for (auto& CollisionObject : CollisionObjects)
	{
		if (MCharacterSprite.getGlobalBounds().intersects(CollisionObject->MCharacterSprite.getGlobalBounds()) &&
			MCharacterName != CollisionObject->MCharacterName)
		{
			collisionParse(CollisionObject->MCharType);
			MCharacterColliding = true;
			processXCollisions(this, CollisionObject);
		}
	}
	
}

void Character::processXCollisions(Character* ObjA, Character* ObjB)
{
	sf::Vector2f ObjACentre =
	{
		(ObjA->MCharacterSprite.getGlobalBounds().left + ObjA->MCharacterSprite.getGlobalBounds().width / 2.0f),
		(ObjA->MCharacterSprite.getGlobalBounds().top + ObjA->MCharacterSprite.getGlobalBounds().height / 2.0f)
	};

	sf::Vector2f ObjBCentre =
	{
		(ObjB->MCharacterSprite.getGlobalBounds().left + ObjB->MCharacterSprite.getGlobalBounds().width / 2.0f),
		(ObjB->MCharacterSprite.getGlobalBounds().top + ObjB->MCharacterSprite.getGlobalBounds().height / 2.0f)
	};

	if (ObjACentre.x < ObjBCentre.x)
	{
		float Offset = -(ObjA->MCharacterSprite.getGlobalBounds().left + ObjA->MCharacterSprite.getGlobalBounds().width
			- ObjB->MCharacterSprite.getGlobalBounds().left);
		sf::Vector2f NewPos = ObjA->MCharacterSprite.getPosition();
		NewPos.x += Offset;
		ObjA->setPosition(NewPos);
	}

	if (ObjACentre.x > ObjBCentre.x)
	{
		float Offset = (ObjB->MCharacterSprite.getGlobalBounds().left + ObjB->MCharacterSprite.getGlobalBounds().width
			- ObjA->MCharacterSprite.getGlobalBounds().left);
		sf::Vector2f NewPos = ObjA->MCharacterSprite.getPosition();
		NewPos.x += Offset;
		ObjA->setPosition(NewPos);
	}
}

void Character::processYCollisions(Character* ObjA, Character* ObjB)
{
	sf::Vector2f ObjACentre =
	{
		(ObjA->MCharacterSprite.getGlobalBounds().left + ObjA->MCharacterSprite.getGlobalBounds().width / 2.0f),
		(ObjA->MCharacterSprite.getGlobalBounds().top + ObjA->MCharacterSprite.getGlobalBounds().height / 2.0f)
	};

	sf::Vector2f ObjBCentre =
	{
		(ObjB->MCharacterSprite.getGlobalBounds().left + ObjB->MCharacterSprite.getGlobalBounds().width / 2.0f),
		(ObjB->MCharacterSprite.getGlobalBounds().top + ObjB->MCharacterSprite.getGlobalBounds().height / 2.0f)
	};

	if (ObjACentre.y < ObjBCentre.y)
	{
		float Offset = -(ObjA->MCharacterSprite.getGlobalBounds().top + ObjA->MCharacterSprite.getGlobalBounds().height
			- ObjB->MCharacterSprite.getGlobalBounds().top);
		sf::Vector2f NewPos = ObjA->MCharacterSprite.getPosition();
		NewPos.y += Offset;
		ObjA->setPosition(NewPos);
	}

	if (ObjACentre.y > ObjBCentre.y)
	{
		float Offset = (ObjB->MCharacterSprite.getGlobalBounds().top + ObjB->MCharacterSprite.getGlobalBounds().height
			- ObjA->MCharacterSprite.getGlobalBounds().top);
		sf::Vector2f NewPos = ObjA->MCharacterSprite.getPosition();
		NewPos.y += Offset;
		ObjA->setPosition(NewPos);
	}
}

void Character::collisionParse(CharacterType Type)
{
	switch (Type)
	{
	case CharTypeWall:
		break;
	case CharTypeTrap:
		setPosition(sf::Vector2f(400, 250)); // Go back to home
		MCharacterColliding = false;
		break;
	case CharTypeWin:
		MWindowRef->close();
		MCharacterColliding = false;
		break;
	case CharTypePlayer:
		break;
	case CharTypeEnemy:
		break;
	}
}
