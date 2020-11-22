#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>

#include "obstacle.hh"
#include "player.hh"

namespace level
{
    class CollisionHandler
    {
        public :
            CollisionHandler(sf::Vector2u window_size,
                    std::vector<Obstacle*> obstacles = {});

            // Getters
            /// {
            std::vector<Obstacle*> obstacles_get(void);
            sf::Vector2u window_size_get(void);
            /// }
            void add_obstacle(Obstacle *obstacle);
            void add_obstacle_vector(std::vector<Obstacle*> obstacles);

            bool check(sf::Vector2f movement, player::Player player);

        private :
            sf::Vector2u window_size_;
            std::vector<Obstacle*> obstacles_;
    };
}
