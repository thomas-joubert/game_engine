#include "textured_object.hh"
#include "player.hh"

#include <SFML/System/Vector2.hpp>
#include <utility>

namespace player
{
    Player::Player(std::string path_to_texture,
            float pos_x,
            float pos_y,
            int len_x,
            int len_y,
            int sprite_origin_x,
            int sprite_origin_y
            )
        : TexturedObject(path_to_texture, pos_x, pos_y, len_x, len_y,
                sprite_origin_x, sprite_origin_y)
    {}

    Player::Player(std::string path_to_texture,
            sf::Vector2i pos,
            sf::Vector2i len,
            sf::Vector2i sprite_origin
            )
        : TexturedObject(path_to_texture, pos, len, sprite_origin)
    {}

    void Player::impulse(sf::Vector2i intensity)
    {
        intensity.x = intensity.x > MAX_SPEED ? MAX_SPEED : intensity.x;
        intensity.y = intensity.y > MAX_SPEED ? MAX_SPEED : intensity.y;

        intensity.x = intensity.x < -MAX_SPEED ? -MAX_SPEED : intensity.x;
        intensity.y = intensity.y < -MAX_SPEED ? -MAX_SPEED : intensity.y;

        velocity_ = intensity;
    }

    void Player::move(void)
    {
        sprite_.move(sf::Vector2f(velocity_));
        shape_.left += velocity_.x;
        shape_.top += velocity_.y;

        velocity_ = {0, 0};
    }

    void collide(std::vector<std::shared_ptr<level::Obstacle>>)
    {
        return;
    }
}
