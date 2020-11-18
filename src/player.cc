#include "textured_object.hh"
#include "player.hh"

#include <utility>

Player::Player(float pos_x,
        float pos_y,
        float len_x,
        float len_y,
        std::string path_to_texture)
    : TexturedObject(pos_x, pos_y, len_x, len_y, path_to_texture)
{}

Player::Player(sf::Vector2f pos,
        sf::Vector2f len,
        std::string path_to_texture)
    : TexturedObject(pos, len, path_to_texture)
{}
