#pragma once

#include "modules.hh"
#include "movable.hh"

namespace modules
{
    class Gravity : public EngineModule
    {
        public :
            int apply(abstract::Movable movable) override;
    };
}
