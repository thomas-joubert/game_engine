#include <SFML/System/Vector2.hpp>
#include <gtest/gtest.h>

#include <stdexcept>
#include <utility>
#include <exception>

class CoordinatesCheckTest : public testing::TestWithParam<int*>
{};

class CoordinatesCheckTestVector : public testing::TestWithParam<sf::Vector2i*>
{};
