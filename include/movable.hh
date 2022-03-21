#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

namespace modules
{
    class EngineModule;
}

#include "modules.hh"

namespace abstract
{
    class Movable
    {
        public :
            Movable() = default;
            virtual void impulse(sf::Vector2i intensity) = 0;
            virtual void apply_modules(void) = 0;

            void add_module(std::shared_ptr<modules::EngineModule> added_module)
            {
                linked_modules_.push_back(added_module);
            };

            std::vector<std::shared_ptr<modules::EngineModule>> get_modules(void)
            {
                return linked_modules_;
            }

            sf::Vector2i velocity_get(void) { return velocity_; }

        protected :
            sf::Vector2i velocity_ = sf::Vector2i(0, 0);
            std::vector<std::shared_ptr<modules::EngineModule>> linked_modules_;
    };
}
