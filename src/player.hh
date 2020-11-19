#include <string>
#include <utility>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "textured_object.hh"

namespace player
{
    /* Hold the basic information about the player, its position, sprite...*/

    class Player : public abstract::TexturedObject
    {
        public :
            Player(std::string path_to_texture,
                    float pos_x,
                    float pos_y,
                    int len_x,
                    int len_y,
                    int sprite_origin_x = 0,
                    int sprite_origin_y = 0
                  );

            Player(std::string path_to_texture,
                    sf::Vector2f pos,
                    sf::Vector2i len,
                    sf::Vector2i sprite_origin = {0, 0}
                  );
    };
}
