#pragma once

#include <utility>
#include <SFML/Graphics.hpp>

/*
** Base object, containing its coordinates, using float to be able to check if 
** the value are negatives or not.
*/

class Object
{
    public :
        Object(float pos_x,
                float pos_y,
                float len_x,
                float len_y);

        Object(sf::Vector2f pos, sf::Vector2f len);

        // Getters
        /// {
        sf::Vector2f pos_get(void);
        sf::Vector2f len_get(void);

        float pos_x_get(void);
        float pos_y_get(void);
        float len_y_get(void);
        float len_x_get(void);
        /// }

    protected :
        sf::Vector2f pos_;
        sf::Vector2f len_;
};
