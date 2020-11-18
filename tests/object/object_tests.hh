#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>

#include <vector>
#include <utility>

class CtrObjectTesterBad : public testing::TestWithParam<int*>
{};

class CtrObjectTesterPairBad : public testing::TestWithParam<sf::Vector2f*>
{};

class CtrObjectTesterGood : public testing::TestWithParam<int*>
{};

class CtrObjectTesterPairGood : public testing::TestWithParam<sf::Vector2f*>
{};
