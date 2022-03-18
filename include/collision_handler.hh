#pragma once

#include <vector>

#include <SFML/System/Vector2.hpp>

#include "obstacle.hh"
#include "player.hh"

namespace level
{
    class CollisionHandler
    {
        public :
            CollisionHandler(sf::Vector2u window_size,
                    std::vector<std::shared_ptr<Obstacle>> obstacles = {});

            // Getters
            /// {
            std::vector<std::shared_ptr<Obstacle>> obstacles_get(void);
            sf::Vector2u window_size_get(void);
            /// }

            void add_obstacle(std::shared_ptr<Obstacle> obstacle);
            void add_obstacle_vector(
                    std::vector<std::shared_ptr<Obstacle>> obstacles);

            bool check(sf::Vector2i movement, player::Player player);

        private :
            sf::Vector2u window_size_;
            std::vector<std::shared_ptr<Obstacle>> obstacles_;
    };
}
