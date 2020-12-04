#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include <stdexcept>
#include <utility>
#include <iostream>

#include "obstacle.hh"
#include "textured_object.hh"

#define TESTFILE "/home/thomas/game_engine/test1.jpg"

TEST(Obstacle_tests, constructor_int)
{
    level::Obstacle ob(TESTFILE, 1, 2, 3, 4, 100, 100);
    ASSERT_EQ(ob.pos_x_get(), 1);
    ASSERT_EQ(ob.pos_y_get(), 2);
    ASSERT_EQ(ob.len_x_get(), 3);
    ASSERT_EQ(ob.len_y_get(), 4);
    ASSERT_EQ(ob.path_to_texture_get(), TESTFILE);
    ASSERT_EQ(ob.sprite_origin_get(), sf::Vector2i(100, 100));
}

TEST(Obstacle_tests, constructor_pair)
{
    level::Obstacle ob(TESTFILE, sf::Vector2i(1, 2), sf::Vector2i(3, 4),
            sf::Vector2i(100, 100));
    ASSERT_EQ(ob.pos_x_get(), 1);
    ASSERT_EQ(ob.pos_y_get(), 2);
    ASSERT_EQ(ob.len_x_get(), 3);
    ASSERT_EQ(ob.len_y_get(), 4);
    ASSERT_EQ(ob.path_to_texture_get(), TESTFILE);
    ASSERT_EQ(ob.sprite_origin_get(), sf::Vector2i(100, 100));
}
