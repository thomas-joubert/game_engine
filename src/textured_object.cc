#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "exceptions/unvalidpath.hh"
#include "textured_object.hh"

TexturedObject::TexturedObject(int pos_x,
            int pos_y,
            int len_x,
            int len_y,
            std::string path_to_texture)
    : Object(pos_x, pos_y, len_x, len_y),
    path_to_texture_(path_to_texture)
{
    if (!texture_.loadFromFile(path_to_texture))
        throw UnvalidPath(path_to_texture);

    sprite_ = sf::Sprite(texture_);
}

sf::Sprite TexturedObject::sprite_get(void)
{
    return sprite_;
}

sf::Texture TexturedObject::texture_get(void)
{
    return texture_;
}

std::string TexturedObject::path_to_texture_get(void)
{
    return path_to_texture_;
}

void TexturedObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite_, states);
}
