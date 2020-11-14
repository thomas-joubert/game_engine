#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "obstacle.hh"
#include "exceptions/unvalidpath.hh"
#include "textured_object.hh"

Obstacle::Obstacle(int pos_x,
            int pos_y,
            int len_x,
            int len_y,
            std::string path_to_texture)
    : TexturedObject(pos_x, pos_y, len_x, len_y,path_to_texture)
{}
