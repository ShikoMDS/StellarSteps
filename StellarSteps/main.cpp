#include "Physics.h"
#include "Level.h"

int main()
{
    sf::RenderWindow Window(sf::VideoMode(800, 600), "Empty SFML Project");
    Window.setFramerateLimit(60);

    sf::Clock GClock;
    float GDeltaTime;

    Level NewLevel;
    NewLevel.loadLevel("Levels/Level1.txt");
    
    auto* Player1 = new Player();
    Player1->setWindowRef(&Window);

    Physics GPhysics;
    GPhysics.addObject(reinterpret_cast<Character*>(Player1));
    GPhysics.addObject(NewLevel.WinTileRef);

    while (Window.isOpen())
    {
        GDeltaTime = GClock.getElapsedTime().asSeconds();
        GClock.restart();

        sf::Event Event{};
        while (Window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                Window.close();
        }

        Window.clear();

        // Input and physics
        Player1->input(GDeltaTime);
        Player1->update(GDeltaTime, NewLevel.MLevelTiles);
        
        GPhysics.updateForces(GDeltaTime, true);

        // Drawing
        Window.draw(Player1->draw());
        NewLevel.draw(&Window);

        Window.display();
    }

    return 0;
}