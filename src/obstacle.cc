#include "obstacle.hh"
#include "exceptions/unvalidpath.hh"

Obstacle::Obstacle(int pos_x,
            int pos_y,
            int len_x,
            int len_y,
            std::string path_to_texture)
    : Object(pos_x, pos_y, len_x, len_y)
{
    sf::Texture texture;
    if (!texture.loadFromFile(path_to_texture))
        throw UnvalidPath(path_to_texture);

    sprite_ = sf::Sprite(texture);
}

sf::Sprite Obstacle::sprite_get(void)
{
    return sprite_;
}
