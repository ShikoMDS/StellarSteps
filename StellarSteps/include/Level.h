#pragma once

#include "Character.h"
#include <fstream>

class Level
{
public:
	Level();
	~Level();

	void loadLevel(std::string FilePath);
	void createLevel();
	void draw(sf::RenderWindow* Window);

	// unloadLevel();

	int CurrentLevel = 1;

	static const int LevelWidth = 15;
	static const int LevelHeight = 20;

	Character* WinTileRef;
	
	// Visual 
	std::vector<Character*> MLevelBackgroundTiles; // Only for drawing

	// Functional
	std::vector<Character*> MLevelTiles; // Collisions of the level, also used for drawing
	
	// Loading files
	char LevelArray[LevelWidth][LevelHeight];

};

