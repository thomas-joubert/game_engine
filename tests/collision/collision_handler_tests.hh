#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include <stdexcept>
#include <utility>
#include <iostream>
#include <tuple>

#include "player.hh"
#include "obstacle.hh"
#include "textured_object.hh"
#include "collision_handler.hh"

#define TESTFILE "/home/thomas/game_engine/test1.jpg"

using check_t = std::tuple<sf::Vector2u, std::vector<level::Obstacle*>, sf::Vector2i, player::Player, bool>;

class ConstructorTests : public testing::TestWithParam<std::pair<sf::Vector2u, std::vector<level::Obstacle*>>>
{};

class CheckTests : public testing::TestWithParam<check_t>
{};
