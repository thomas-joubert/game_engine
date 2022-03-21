#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

namespace abstract
{
    class Movable
    {
        public :
            Movable() = default;
            virtual void impulse(sf::Vector2i intensity) = 0;
            sf::Vector2i velocity_get(void) { return velocity_; }

        protected :
            sf::Vector2i velocity_ = sf::Vector2i(0, 0);
    };
}
