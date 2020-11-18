#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "obstacle.hh"
#include "exceptions/unvalidpath.hh"
#include "textured_object.hh"

Obstacle::Obstacle(float pos_x,
            float pos_y,
            float len_x,
            float len_y,
            std::string path_to_texture)
    : TexturedObject(pos_x, pos_y, len_x, len_y,path_to_texture)
{}

Obstacle::Obstacle(sf::Vector2f pos,
        sf::Vector2f len,
        std::string path_to_texture)
    : TexturedObject(pos, len, path_to_texture)
{}
