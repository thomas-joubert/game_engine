#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <exception>
#include <stdexcept>

#include "object.hh"

Object::Object(float pos_x,
        float pos_y,
        int len_x,
        int len_y)
    : pos_(pos_x, pos_y),
    len_(len_x, len_y)
{
    if (pos_x < 0 || pos_y < 0 || len_x <= 0 || len_y <= 0)
        throw std::invalid_argument("An object cannot be initialize with negative values");
}

Object::Object(sf::Vector2f pos,
        sf::Vector2i len)
    : pos_(pos),
    len_(len)
{
    if (pos.x < 0 || pos.x < 0 || len.x <= 0 || len.y <= 0)
        throw std::invalid_argument("An object cannot be initialize with negative values");
}

float Object::pos_x_get(void)
{
    return pos_.x;
}

float Object::pos_y_get(void)
{
    return pos_.y;
}

int Object::len_x_get(void)
{
    return len_.x;
}

int Object::len_y_get(void)
{
    return len_.y;
}

sf::Vector2f Object::pos_get(void)
{
    return pos_;
}

sf::Vector2i Object::len_get(void)
{
    return len_;
}
