#pragma once

#include <string>
#include <utility>
#include <memory>

#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "textured_object.hh"
#include "movable.hh"
#include "obstacle.hh"

#define MAX_SPEED 100

/* Hold the basic information about the player, its position, sprite...*/
namespace player
{
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
                    sf::Vector2i pos,
                    sf::Vector2i len,
                    sf::Vector2i sprite_origin = {0, 0}
                  );

            void impulse(sf::Vector2i intensity) override;
            void move(void);
            void collide(std::vector<std::shared_ptr<level::Obstacle>> collided);
    };
}
