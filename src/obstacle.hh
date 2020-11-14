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
    Obstacle(int pos_x,
            int pos_y,
            int len_x,
            int len_y,
            std::string path_to_texture);
};
