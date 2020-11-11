#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "object.hh"

/* Hold the basic information about the player, its position, sprite...*/

class Player : public Object, public sf::Drawable
{
    public :
        Player(int pos_x,
                int pos_y,
                int len_x,
                int len_y,
                std::string path_to_texture);

        sf::Sprite sprite_get(void);
        sf::Texture texture_get(void);

    private :
        sf::Sprite sprite_;
        sf::Texture texture_;
};
