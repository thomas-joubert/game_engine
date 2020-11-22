#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "object.hh"
#include "obstacle.hh"
#include "player.hh"

#define ACCELERATION 10

bool movement(sf::Event event, player::Player &player)
{
    if (event.key.code == sf::Keyboard::Up)
        player.impulse(sf::Vector2f(0, -ACCELERATION));
    else if (event.key.code == sf::Keyboard::Down)
        player.impulse(sf::Vector2f(0, ACCELERATION));
    else if (event.key.code == sf::Keyboard::Left)
        player.impulse(sf::Vector2f(-ACCELERATION, 0));
    else if (event.key.code == sf::Keyboard::Right)
        player.impulse(sf::Vector2f(ACCELERATION, 0));
    else
        return false;

    return true;
}

int main(void)
{
    // Main window instanciation
    sf::RenderWindow renderWindow(sf::VideoMode(1000, 1000, sf::Style::Default),
            "Something");
    renderWindow.setVerticalSyncEnabled(true);

    auto obstacle = level::Obstacle("/home/thomas/game_engine/test1.jpg",
            100, 100, 100, 100);
    auto player = player::Player("/home/thomas/game_engine/test2.png",
            0, 0, 100, 100);

    while (renderWindow.isOpen())
    {
        // Stores the event (keyboards...)
        sf::Event event;

        //pollEvent renvoie true si un event est en attente, false sinon
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed
                    || (event.type == sf::Event::KeyPressed
                        && event.key.code == sf::Keyboard::Tab))
                renderWindow.close();
            else if (event.type == sf::Event::KeyPressed)
                movement(event, player);

            player.move();
            renderWindow.clear();
            renderWindow.draw(obstacle);
            renderWindow.draw(player);
            renderWindow.display();
        }
    }

    return 0;
}
