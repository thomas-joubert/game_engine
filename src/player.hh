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
        Player(int pos_x,
                int pos_y,
                int len_x,
                int len_y,
                std::string path_to_texture);

        Player(std::pair<int, int> pos,
                std::pair<int, int> len,
                std::string path_to_texture);
};
