#include <SFML/System/Vector2.hpp>
#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include "player_tests.hh"
#include "textured_object.hh"

#define TESTFILE "/home/thomas/game_engine/test1.jpg"

TEST(Player_tests_constructor, constructor_int)
{
    player::Player ob(TESTFILE, 1, 2, 3, 4, 100, 100);
    ASSERT_EQ(ob.pos_x_get(), 1);
    ASSERT_EQ(ob.pos_y_get(), 2);
    ASSERT_EQ(ob.len_x_get(), 3);
    ASSERT_EQ(ob.len_y_get(), 4);
    ASSERT_EQ(ob.path_to_texture_get(), TESTFILE);
    ASSERT_EQ(ob.sprite_origin_get(), sf::Vector2i(100, 100));
}

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
            sf::Vector2i(1, 65)
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
            sf::Vector2i(2003, 2002)
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
            sf::Vector2i(-2003, -2002)
            ));

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
