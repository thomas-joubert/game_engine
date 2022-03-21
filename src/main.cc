#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <memory>

#include "object.hh"
#include "obstacle.hh"
#include "player.hh"
#include "collision_handler.hh"
#include "gravity.hh"
#include "logger.hh"

#define ACCELERATION 10
#define FRAMERATE 60

bool movement(sf::Event event, player::Player &player, level::CollisionHandler collisionHandler)
{
    auto up = sf::Vector2i(0, -ACCELERATION);
    auto down = sf::Vector2i(0, ACCELERATION);
    auto left = sf::Vector2i(-ACCELERATION, 0);
    auto right = sf::Vector2i(ACCELERATION, 0);

    logging::InfoLogger::instance() << "Key pressed \n";
    std::cout << event.key.code << "\n";
    if (event.key.code == sf::Keyboard::Up && !collisionHandler.check(up, player))
        player.impulse(up);
    else if (event.key.code == sf::Keyboard::Down && !collisionHandler.check(down, player))
        player.impulse(down);
    else if (event.key.code == sf::Keyboard::Left && !collisionHandler.check(left, player))
        player.impulse(left);
    else if (event.key.code == sf::Keyboard::Right && !collisionHandler.check(right, player))
        player.impulse(right);
    else if (event.key.code == sf::Keyboard::Tab)
    {
        logging::InfoLogger::instance() << "Tab key pressed, closing window...\n";
    }
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

    sf::Clock clock;

    auto obstacle = level::Obstacle(
            "/home/ameno/perso/projects/game_engine/test1.jpg",
            100, 100, 100, 100);
    auto player = player::Player(
            "/home/ameno/perso/projects/game_engine/test1.jpg",
            0, 0, 100, 100);

    player.add_module(std::make_shared<modules::Gravity>());

    auto collisionHandler = level::CollisionHandler(renderWindow.getSize());
    collisionHandler.add_obstacle(std::make_shared<level::Obstacle>(obstacle));

    while (renderWindow.isOpen())
    {
        // Stores the event (keyboards...)
        clock.restart();
        sf::Event event;

        //pollEvent renvoie true si un event est en attente, false sinon
        while (clock.getElapsedTime().asMilliseconds() < 1000 / FRAMERATE)
        {
            renderWindow.pollEvent(event);
        }

        if (event.type == sf::Event::Closed)
        {
            renderWindow.close();
            logging::InfoLogger::instance() << "Tab key pressed, closing window...\n";
        }
        else if (event.type == sf::Event::KeyPressed)
            movement(event, player, collisionHandler);

        player.move();
        player.apply_modules();
        renderWindow.clear();
        renderWindow.draw(obstacle);
        renderWindow.draw(player);
        renderWindow.display();
    }

    return 0;
}
