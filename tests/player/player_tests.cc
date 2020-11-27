#include <SFML/System/Vector2.hpp>
#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include "player_tests.hh"

TEST_P(PlayerTestsImpulseGood, impulseTestsGood)
{
    player::Player player("/home/thomas/game_engine/test1.jpg", {0, 0}, {1, 1});
    player.impulse(GetParam());
    ASSERT_EQ(player.velocity_get(), GetParam());
}

INSTANTIATE_TEST_SUITE_P(PlayerTests, PlayerTestsImpulseGood,
        ::testing::Values (
            sf::Vector2i(1, 1),
            sf::Vector2i(2, 2),
            sf::Vector2i(100, 100),
            sf::Vector2i(1, 0),
            sf::Vector2i(1.3, 65.7)
            ));

TEST_P(PlayerTestsImpulseBadUpperLimit, impulseTestsBadUpperLimit)
{
    player::Player player("/home/thomas/game_engine/test1.jpg", {0, 0}, {1, 1});
    player.impulse(GetParam());
    ASSERT_EQ(player.velocity_get(), sf::Vector2i(100, 100));
}

INSTANTIATE_TEST_SUITE_P(PlayerTests, PlayerTestsImpulseBadUpperLimit,
        ::testing::Values (
            sf::Vector2i(101, 101),
            sf::Vector2i(2003.14, 2002.54)
            ));

TEST_P(PlayerTestsImpulseBadLowerLimit, impulseTestsBadLowerLimit)
{
    player::Player player("/home/thomas/game_engine/test1.jpg", {0, 0}, {1, 1});
    player.impulse(GetParam());
    ASSERT_EQ(player.velocity_get(), sf::Vector2i(-100, -100));
}

INSTANTIATE_TEST_SUITE_P(PlayerTests, PlayerTestsImpulseBadLowerLimit,
        ::testing::Values (
            sf::Vector2i(-101, -101),
            sf::Vector2i(-2003.14, -2002.54)
            ));

TEST(PlayerTests, friction)
{
    player::Player player("/home/thomas/game_engine/test1.jpg", {0, 0}, {1, 1});
    player.impulse({100, 100});
    player.friction();

    ASSERT_EQ(player.velocity_get(), sf::Vector2i(50, 50));
}

TEST(PlayerTests, frictionNegative)
{
    player::Player player("/home/thomas/game_engine/test1.jpg", {0, 0}, {1, 1});
    player.impulse({-100, -100});
    player.friction();

    ASSERT_EQ(player.velocity_get(), sf::Vector2i(-50, -50));
}

TEST_P(PlayerTestsMoveGood, MoveTestsGood)
{
    player::Player player("/home/thomas/game_engine/test1.jpg", {0, 0}, {1, 1});
    player.impulse(GetParam());
    player.move();
    ASSERT_EQ(player.pos_get(), GetParam());
}

INSTANTIATE_TEST_SUITE_P(PlayerTests, PlayerTestsMoveGood,
        ::testing::Values (
            sf::Vector2i(1, 1),
            sf::Vector2i(2, 2),
            sf::Vector2i(100, 100),
            sf::Vector2i(1, 0),
            sf::Vector2i(1, 65)
            ));

TEST_P(PlayerTestsMoveBadUpperLimit, MoveTestsBadUpperLimit)
{
    player::Player player("/home/thomas/game_engine/test1.jpg", {0, 0}, {1, 1});
    player.impulse(GetParam());
    player.move();
    ASSERT_EQ(player.pos_get(), sf::Vector2i(100, 100));
}

INSTANTIATE_TEST_SUITE_P(PlayerTests, PlayerTestsMoveBadUpperLimit,
        ::testing::Values (
            sf::Vector2i(101, 101),
            sf::Vector2i(2003, 2002)
            ));

TEST_P(PlayerTestsMoveBadLowerLimit, MoveTestsBadLowerLimit)
{
    player::Player player("/home/thomas/game_engine/test1.jpg", {0, 0}, {1, 1});
    player.impulse(GetParam());
    player.move();
    ASSERT_EQ(player.pos_get(), sf::Vector2i(-100, -100));
}

INSTANTIATE_TEST_SUITE_P(PlayerTests, PlayerTestsMoveBadLowerLimit,
        ::testing::Values (
            sf::Vector2i(-101, -101),
            sf::Vector2i(-2003, -2002)
            ));
