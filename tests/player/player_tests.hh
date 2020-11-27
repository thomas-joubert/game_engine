#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>

#include <vector>
#include <utility>

#include "player.hh"

class PlayerTestsImpulseGood : public testing::TestWithParam<sf::Vector2i>
{};

class PlayerTestsImpulseBadUpperLimit : public testing::TestWithParam<sf::Vector2i>
{};

class PlayerTestsImpulseBadLowerLimit : public testing::TestWithParam<sf::Vector2i>
{};

class PlayerTestsMoveGood : public testing::TestWithParam<sf::Vector2i>
{};

class PlayerTestsMoveBadUpperLimit : public testing::TestWithParam<sf::Vector2i>
{};

class PlayerTestsMoveBadLowerLimit : public testing::TestWithParam<sf::Vector2i>
{};
