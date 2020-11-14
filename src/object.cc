#include <exception>
#include <stdexcept>

#include "object.hh"

Object::Object(int pos_x,
        int pos_y,
        int len_x,
        int len_y)
{
    if (pos_x < 0 || pos_y < 0 || len_x < 0 || len_y < 0)
        throw std::invalid_argument("An object cannot be initialize with negative values");
    pos_ = std::make_pair(pos_x, pos_y);
    len_ = std::make_pair(len_x, len_y);
}

Object::Object(std::pair<int, int> pos,
        std::pair<int, int> len)
    : pos_(pos),
    len_(len)
{
    if (pos.first < 0 || pos.second < 0 || len.first < 0 || len.second < 0)
        throw std::invalid_argument("An object cannot be initialize with negative values");
}

int Object::pos_x_get(void)
{
    return pos_.first;
}

int Object::pos_y_get(void)
{
    return pos_.second;
}

int Object::len_x_get(void)
{
    return len_.first;
}

int Object::len_y_get(void)
{
    return len_.second;
}

std::pair<int, int> Object::pos_get(void)
{
    return pos_;
}

std::pair<int, int> Object::len_get(void)
{
    return len_;
}
