#include <SFML/System/Vector2.hpp>

#include "collision_handler.hh"
#include "obstacle.hh"
#include "player.hh"

namespace level
{
    CollisionHandler::CollisionHandler(sf::Vector2u window_size,
            std::vector<std::shared_ptr<Obstacle>> obstacles)
        : window_size_(window_size),
        obstacles_(obstacles)
    {}

    std::vector<std::shared_ptr<Obstacle>> CollisionHandler::obstacles_get(void)
    {
        return obstacles_;
    }

    sf::Vector2u CollisionHandler::window_size_get(void)
    {
        return window_size_;
    }

    void CollisionHandler::add_obstacle(std::shared_ptr<Obstacle> obstacle)
    {
        obstacles_.push_back(obstacle);
    }

    void CollisionHandler::add_obstacle_vector(
            std::vector<std::shared_ptr<Obstacle>> obstacles)
    {
        obstacles_.insert(obstacles_.end(), obstacles.begin(), obstacles.end());
    }

    bool CollisionHandler::check(sf::Vector2i movement, player::Player player)
    {
        player.impulse(movement);
        player.move();

        for (auto& i : obstacles_)
        {
            if (player.shape_get().intersects(i->shape_get()))
            {
                player.impulse(-movement);
                player.move();
                return true;
            }
        }

        player.impulse(-movement);
        player.move();

        return false;
    }
}
