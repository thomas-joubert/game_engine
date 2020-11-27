#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>

#include <vector>
#include <utility>

class CtrObjectTesterBadCoordinates : public testing::TestWithParam<int*>
{};

class CtrObjectTesterPairBadCoordinates : public testing::TestWithParam<sf::Vector2i*>
{};

class CtrObjectTesterGoodCoordinates : public testing::TestWithParam<int*>
{};

class CtrObjectTesterPairGoodCoordinates : public testing::TestWithParam<sf::Vector2i*>
{};

class CtrObjectTesterBadLen : public testing::TestWithParam<int*>
{};

class CtrObjectTesterPairBadLen : public testing::TestWithParam<sf::Vector2i*>
{};
