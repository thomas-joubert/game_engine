#include <SFML/System/Vector2.hpp>
#include <gtest/gtest.h>

#include <stdexcept>
#include <utility>
#include <exception>

#include "textured_object_tests.hh"

#include "../../src/textured_object.hh"
#include "../../src/exceptions/unvalidpath.hh"

#define TESTFILE "/home/thomas/game_engine/test1.jpg"

TEST(TexturedObject, Ctor_unvalid_path)
{
    ASSERT_THROW(TexturedObject(0, 0, 0, 0, "failed"), UnvalidPath);
}

TEST(TexturedObject, Ctor_valid_path_str)
{
    TexturedObject obj(0, 0, 0, 0, TESTFILE);
    ASSERT_EQ(obj.path_to_texture_get(), TESTFILE);
}

TEST(TexturedObject, sprite_position_0)
{
    TexturedObject obj(0, 0, 0, 0, TESTFILE);
    ASSERT_EQ(obj.path_to_texture_get(), TESTFILE);
}

TEST_P(CoordinatesCheckTest, checkCoordinates)
{
    int* args = GetParam();

    TexturedObject obj(args[0], args[1], 1, 1, TESTFILE);

    ASSERT_EQ(obj.pos_get(), obj.sprite_get().getPosition());
}

int a1[]{0, 0};
int b1[]{10, 10};
int c1[]{50, 190};
int d1[]{30, 34};

INSTANTIATE_TEST_SUITE_P(TexturedObject, CoordinatesCheckTest,
        ::testing::Values(
            a1, b1, c1, d1
            ));

TEST_P(CoordinatesCheckTestVector, checkCoordinates)
{
    sf::Vector2f* args = GetParam();

    TexturedObject obj(args[0], args[1], TESTFILE);

    ASSERT_EQ(obj.pos_get(), obj.sprite_get().getPosition());
}

sf::Vector2f a2[]{{0, 0}, {100, 100}};
sf::Vector2f b2[]{{10, 10}, {50, 50}};
sf::Vector2f c2[]{{50, 190}, {14, 69}};
sf::Vector2f d2[]{{30, 34}, {45, 9}};

INSTANTIATE_TEST_SUITE_P(TexturedObject, CoordinatesCheckTestVector,
        ::testing::Values(
            a2, b2, c2, d2
            ));
