#pragma once

#include "movable.hh"
#include <memory>

namespace abstract
{
    class Movable;
}

namespace modules
{
    class EngineModule
    {
        public :
            virtual int apply(abstract::Movable *movable) = 0;
    };
}
