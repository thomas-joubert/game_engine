#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "object.hh"
#include "obstacle.hh"

int main(void)
{
    // Main window instanciation
    sf::RenderWindow renderWindow(sf::VideoMode(1000, 1000, sf::Style::Default), "Something");
    renderWindow.setVerticalSyncEnabled(true);

    auto obstacle = Obstacle("/home/thomas/game_engine/test1.jpg", 100, 100, 100, 100);

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

            renderWindow.clear();
            renderWindow.draw(obstacle);
            renderWindow.display();
        }
    }

    return 0;
}
