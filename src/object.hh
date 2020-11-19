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
                int len_x,
                int len_y);

        Object(sf::Vector2f pos,
                sf::Vector2i len);

        // Getters
        /// {
        sf::Vector2f pos_get(void);
        sf::Vector2i len_get(void);

        float pos_x_get(void);
        float pos_y_get(void);
        int len_y_get(void);
        int len_x_get(void);
        /// }

    protected :
        sf::Vector2f pos_;
        sf::Vector2i len_;
};
