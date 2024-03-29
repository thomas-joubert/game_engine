#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include "exceptions/unvalidpath.hh"
#include "textured_object.hh"

namespace abstract
{
    TexturedObject::TexturedObject(std::string path_to_texture,
            float pos_x,
            float pos_y,
            int len_x,
            int len_y,
            int sprite_origin_x,
            int sprite_origin_y
            )
        : Object(pos_x, pos_y, len_x, len_y),
        path_to_texture_(path_to_texture),
        sprite_origin_(sprite_origin_x, sprite_origin_y)
    {
        if (!texture_.loadFromFile(path_to_texture))
            throw UnvalidPath(path_to_texture);

        sprite_ = sf::Sprite(texture_, shape_);
        sprite_.setPosition(shape_.left, shape_.top);
    }


    TexturedObject::TexturedObject(std::string path_to_texture,
            sf::Vector2i pos,
            sf::Vector2i len,
            sf::Vector2i sprite_origin
            )
        : Object(pos, len),
        path_to_texture_(path_to_texture),
        sprite_origin_(sprite_origin)
    {
        if (!texture_.loadFromFile(path_to_texture))
            throw UnvalidPath(path_to_texture);

        sprite_ = sf::Sprite(texture_, shape_);
        sprite_.setPosition(shape_.left, shape_.top);
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

    sf::Vector2i TexturedObject::sprite_origin_get(void)
    {
        return sprite_origin_;
    }
}
