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
        Obstacle(std::string path_to_texture, 
                float pos_x,
                float pos_y,
                int len_x,
                int len_y,
                int sprite_origin_x = 0,
                int sprite_origin_y = 0
                );

        Obstacle(std::string path_to_texture,
                sf::Vector2f pos,
                sf::Vector2i len,
                sf::Vector2i sprite_origin = {0, 0}
                );
};
