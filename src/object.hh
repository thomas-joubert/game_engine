#pragma once

#include <utility>

/*
** Base object, containing its coordinates, using int to be able to check if 
** the value are negatives or not.
*/

class Object
{
    public :
        Object(int pos_x,
                int pos_y,
                int len_x,
                int len_y);

        Object(std::pair<int, int> pos, std::pair<int, int> len);

        // Getters
        /// {
        std::pair<int, int> pos_get(void);
        std::pair<int, int> len_get(void);

        int pos_x_get(void);
        int pos_y_get(void);
        int len_y_get(void);
        int len_x_get(void);
        /// }

    protected :
        std::pair<int, int> pos_;
        std::pair<int, int> len_;
};
