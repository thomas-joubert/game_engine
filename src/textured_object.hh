#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <string>
#include <utility>

#include "object.hh"

/* Represents an abstract object associated to a texture */ 

class TexturedObject : public Object, public sf::Drawable
{
    public :
        TexturedObject(float pos_x,
                float pos_y,
                float len_x,
                float len_y,
                std::string path_to_texture);

        TexturedObject(sf::Vector2f pos,
                sf::Vector2f len,
                std::string path_to_texture);

        // Getters
        /// {
        sf::Sprite sprite_get(void);
        sf::Texture texture_get(void);
        std::string path_to_texture_get(void);
        /// }

    protected :
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::Texture texture_;
        sf::Sprite sprite_;
        std::string path_to_texture_;
};
