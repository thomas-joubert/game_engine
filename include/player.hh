#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <utility>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "textured_object.hh"
#include "movable.hh"

#define MAX_SPEED 100

namespace player
{
    /* Hold the basic information about the player, its position, sprite...*/

    class Player : public abstract::TexturedObject, public abstract::Movable
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

            void impulse(sf::Vector2i intensity) override;
    };
}
