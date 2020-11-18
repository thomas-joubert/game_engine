#include <string>
#include <utility>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "textured_object.hh"

/* Hold the basic information about the player, its position, sprite...*/

class Player : public TexturedObject
{
    public :
        Player(float pos_x,
                float pos_y,
                float len_x,
                float len_y,
                std::string path_to_texture);

        Player(sf::Vector2f pos,
                sf::Vector2f len,
                std::string path_to_texture);
};
