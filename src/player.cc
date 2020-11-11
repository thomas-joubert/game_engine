#include "object.hh"
#include "player.hh"
#include "exceptions/unvalidpath.hh"

Player::Player(int pos_x,
                int pos_y,
                int len_x,
                int len_y,
                std::string path_to_texture)
    : Object(pos_x, pos_y, len_x, len_y)
{
    if (!texture_.loadFromFile(path_to_texture))
        throw UnvalidPath(path_to_texture);

    sprite_ = sf::Sprite(texture_);
}

sf::Sprite Player::sprite_get(void)
{
    return sprite_;
}

sf::Texture Player::texture_get(void)
{
    return texture_;
}
