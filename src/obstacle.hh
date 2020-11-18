#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <string>

#include "textured_object.hh"

/* Represents an obstacle, unmovable object that has a particular sprite */

class Obstacle : public TexturedObject
{
    public :
        Obstacle(float pos_x,
                float pos_y,
                float len_x,
                float len_y,
                std::string path_to_texture);

        Obstacle(sf::Vector2f pos,
                sf::Vector2f len,
                std::string path_to_texture);
};
