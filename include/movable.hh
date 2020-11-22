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
            virtual void impulse(sf::Vector2f intensity) = 0;
            virtual void friction(void) = 0;

        protected :
            sf::Vector2f velocity_ = sf::Vector2f(0, 0);
    };
}
