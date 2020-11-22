#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>

#include <vector>
#include <utility>

#include "player.hh"

class PlayerTestsImpulseGood : public testing::TestWithParam<sf::Vector2f>
{};

class PlayerTestsImpulseBadUpperLimit : public testing::TestWithParam<sf::Vector2f>
{};

class PlayerTestsImpulseBadLowerLimit : public testing::TestWithParam<sf::Vector2f>
{};

class PlayerTestsMoveGood : public testing::TestWithParam<sf::Vector2f>
{};

class PlayerTestsMoveBadUpperLimit : public testing::TestWithParam<sf::Vector2f>
{};

class PlayerTestsMoveBadLowerLimit : public testing::TestWithParam<sf::Vector2f>
{};
