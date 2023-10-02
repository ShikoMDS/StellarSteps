#pragma once

#include "SFML/Graphics.hpp"

class Camera
{
public:
	sf::Vector2f MCurrentPosition;
	sf::View* MCameraViewReference;

	Camera(sf::Vector2f CameraPosition, sf::Vector2i CameraDimensions, sf::RenderWindow* WindowRef);
	~Camera();


};

