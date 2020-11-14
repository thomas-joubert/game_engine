#include <exception>
#include <stdexcept>

#include "object.hh"

Object::Object(int pos_x,
        int pos_y,
        int len_x,
        int len_y)
    : pos_x_(pos_x),
    pos_y_(pos_y),
    len_x_(len_x),
    len_y_(len_y)
{
    if (pos_x < 0 || pos_y < 0 || len_x < 0 || len_y < 0)
        throw std::invalid_argument("An object cannot be initialize with negative values");
}


int Object::pos_x_get(void)
{
    return pos_x_;
}

int Object::pos_y_get(void)
{
    return pos_y_;
}

int Object::len_x_get(void)
{
    return len_x_;
}

int Object::len_y_get(void)
{
    return len_y_;
}
