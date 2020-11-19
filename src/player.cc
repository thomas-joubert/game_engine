#include "textured_object.hh"
#include "player.hh"

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
            sf::Vector2f pos,
            sf::Vector2i len,
            sf::Vector2i sprite_origin
            )
        : TexturedObject(path_to_texture, pos, len, sprite_origin)
    {}
}
