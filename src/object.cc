#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <exception>
#include <stdexcept>

#include "object.hh"

namespace abstract
{
    Object::Object(float pos_x,
            float pos_y,
            int len_x,
            int len_y)
        : shape_(pos_x, pos_y, len_x, len_y)
    {
        if (pos_x < 0 || pos_y < 0 || len_x <= 0 || len_y <= 0)
            throw std::invalid_argument("An object cannot be initialize with negative values");
    }

    Object::Object(sf::Vector2i pos,
            sf::Vector2i len)
        : shape_(sf::Vector2i(pos), len)
    {
        if (pos.x < 0 || pos.x < 0 || len.x <= 0 || len.y <= 0)
            throw std::invalid_argument("An object cannot be initialize with negative values");
    }

    float Object::pos_x_get(void)
    {
        return shape_.left;
    }

    float Object::pos_y_get(void)
    {
        return shape_.top;
    }

    int Object::len_x_get(void)
    {
        return shape_.width;
    }

    int Object::len_y_get(void)
    {
        return shape_.height;
    }

    sf::Vector2i Object::pos_get(void)
    {
        return sf::Vector2i(shape_.left, shape_.top);
    }

    sf::Vector2i Object::len_get(void)
    {
        return sf::Vector2i(shape_.width, shape_.height);
    }

    sf::IntRect Object::shape_get(void)
    {
        return shape_;
    }
}
