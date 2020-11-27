#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <SFML/System/Vector2.hpp>
#include <string>
#include <utility>

#include "object.hh"

namespace abstract
{
    /* Represents an abstract object associated to a texture */ 

    class TexturedObject : public Object, public sf::Drawable
    {
        public :
            TexturedObject(std::string path_to_texture,
                    float pos_x,
                    float pos_y,
                    int len_x,
                    int len_y,
                    int sprite_origin_x = 0,
                    int sprite_origin_y = 0
                    );

            TexturedObject(std::string path_to_texture,
                    sf::Vector2i pos,
                    sf::Vector2i len,
                    sf::Vector2i sprite_origin = {0, 0}
                    );

            // Getters
            /// {
            sf::Sprite sprite_get(void);
            sf::Texture texture_get(void);
            std::string path_to_texture_get(void);
            sf::Vector2i sprite_origin_get(void);
            /// }

        protected :
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
            sf::Texture texture_;
            sf::Sprite sprite_;
            std::string path_to_texture_;
            sf::Vector2i sprite_origin_;
    };
}
