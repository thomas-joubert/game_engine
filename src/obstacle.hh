#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <string>

#include "object.hh"

/* Represents an obstacle, unmovable object that has a particular sprite */

class Obstacle : public Object, public sf::Drawable
{
    public :
    Obstacle(int pos_x,
            int pos_y,
            int len_x,
            int len_y,
            std::string path_to_texture);

    sf::Sprite sprite_get(void);
    sf::Texture texture_get(void);

    private :
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::Texture texture_;
        sf::Sprite sprite_;
        std::string path_to_texture_;
};
