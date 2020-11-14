#include "textured_object.hh"
#include "player.hh"

#include <utility>

Player::Player(int pos_x,
        int pos_y,
        int len_x,
        int len_y,
        std::string path_to_texture)
    : TexturedObject(pos_x, pos_y, len_x, len_y, path_to_texture)
{}

Player::Player(std::pair<int, int> pos,
        std::pair<int, int> len,
        std::string path_to_texture)
    : TexturedObject(pos, len, path_to_texture)
{}
