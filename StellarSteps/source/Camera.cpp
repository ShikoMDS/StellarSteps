#include "Camera.h"

Camera::Camera(sf::Vector2f CameraPosition, sf::Vector2i CameraDimensions, sf::RenderWindow* WindowRef)
{
	MCameraViewReference = new sf::View(CameraPosition, (sf::Vector2f)CameraDimensions);
	WindowRef->setView(*MCameraViewReference);
}

Camera::~Camera()
{

}
