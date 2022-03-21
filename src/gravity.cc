#include "gravity.hh"

namespace modules
{
    int Gravity::apply(abstract::Movable *movable)
    {
        movable->impulse({0, 10});

        return 0;
    }
}
