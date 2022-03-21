#include "gravity.hh"

namespace modules
{
    int Gravity::apply(abstract::Movable *movable)
    {
        movable->impulse({0, 5});

        return 0;
    }
}
