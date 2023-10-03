#include "Level.h"

Level::Level() = default;

Level::~Level()
{
	for (auto& Tile : MLevelTiles)
	{
		delete Tile;
	}
	delete WinTileRef;
}

void Level::loadLevel(std::string FilePath)
{
	std::fstream LoadFileStream;
	LoadFileStream.open(FilePath, std::ios::in);

	std::string LoadFileString;
	int LineCount = 0;

	if (LoadFileStream.is_open())
	{
		while (std::getline(LoadFileStream, LoadFileString))
		{
			for (int I = 0; I < static_cast<int>(LoadFileString.size()); I++)
			{
				LevelArray[LineCount][I] = LoadFileString[I];
			}

			LineCount++;
		}

		LoadFileStream.close();
	}

	createLevel();
}

void Level::createLevel()
{
	for (int X = 0; X < LevelHeight; X++)
	{
		for (int Y = 0; Y < LevelWidth; Y++)
		{
			if (LevelArray[Y][X] == 'x')
			{
				//Character* NewTile = new Character();
				auto* NewTile = new Character();
				NewTile->setCharType(CharTypeWall);
				NewTile->setPosition(sf::Vector2f(static_cast<float>(X * 32), static_cast<float>(Y * 32))); // Could be a variable for sprite
				MLevelTiles.push_back(NewTile);
			}

			if (LevelArray[Y][X] == 't')
			{
				//Character* NewTile = new Character();
				auto* NewTile = new Character();
				NewTile->setCharType(CharTypeTrap);
				NewTile->setPosition(sf::Vector2f(static_cast<float>(X * 32), static_cast<float>(Y * 32))); // Could be a variable for sprite
				MLevelTiles.push_back(NewTile);
			}

			if (LevelArray[Y][X] == 'w')
			{
				//Character* NewTile = new Character();
				auto* NewTile = new Character();
				NewTile->setCharType(CharTypeWin);
				NewTile->setPosition(sf::Vector2f(static_cast<float>(X * 32), static_cast<float>(Y * 32))); // Could be a variable for sprite
				WinTileRef = NewTile;
			}
		}
	}
}

void Level::draw(sf::RenderWindow* Window)
{
	for (const auto& MLevelTile : MLevelTiles)
	{
		Window->draw(MLevelTile->draw());
	}

	if (WinTileRef)
	{
		Window->draw(WinTileRef->draw());
	}
}
