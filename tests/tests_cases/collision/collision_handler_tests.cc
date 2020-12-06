#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include <stdexcept>
#include <utility>
#include <iostream>

#include "collision_handler_tests.hh"

#include "obstacle.hh"
#include "textured_object.hh"
#include "collision_handler.hh"

#define TESTFILE "/home/thomas/game_engine/test1.jpg"

TEST(CollisionHandler, Constructor_one_arg)
{
    level::CollisionHandler col(sf::Vector2u(10, 10));
    ASSERT_EQ(col.obstacles_get().empty(), true);
    ASSERT_EQ(col.window_size_get(), sf::Vector2u(10, 10));
}

TEST(CollisionHandler, add_one_obstacle)
{
    level::CollisionHandler col(sf::Vector2u(10, 10));
    level::Obstacle ob(TESTFILE, 0, 0, 1, 1);

    col.add_obstacle(&ob);

    ASSERT_EQ(col.obstacles_get().size(), 1);
    ASSERT_EQ(col.obstacles_get()[0], &ob);
}

TEST(CollisionHandler, add_two_obstacles)
{
    level::CollisionHandler col(sf::Vector2u(10, 10));
    level::Obstacle ob(TESTFILE, 0, 0, 1, 1);
    level::Obstacle ob1(TESTFILE, 0, 0, 1, 1);

    col.add_obstacle(&ob);
    col.add_obstacle(&ob1);

    ASSERT_EQ(col.obstacles_get().size(), 2);
}

TEST(CollisionHandler, add_obstacles_vector)
{
    level::CollisionHandler col(sf::Vector2u(10, 10));
    level::Obstacle ob(TESTFILE, 0, 0, 1, 1);
    level::Obstacle ob1(TESTFILE, 0, 0, 1, 1);
    std::vector<level::Obstacle*> vec = {&ob, &ob1};

    col.add_obstacle_vector(vec);

    ASSERT_EQ(col.obstacles_get().size(), 2);
}

TEST(CollisionHandler, add_obstacles_vector_empty)
{
    level::CollisionHandler col(sf::Vector2u(10, 10));
    std::vector<level::Obstacle*> vec;

    col.add_obstacle_vector(vec);

    ASSERT_EQ(col.obstacles_get().size(), 0);
}

TEST(CollisionHandler, add_obstacles_vector_additive)
{
    level::Obstacle ob(TESTFILE, 0, 0, 1, 1);
    level::Obstacle ob1(TESTFILE, 0, 0, 1, 1);
    std::vector<level::Obstacle*> vec = {&ob, &ob1};
    level::CollisionHandler col(sf::Vector2u(10, 10), vec);

    level::Obstacle ob2(TESTFILE, 0, 0, 1, 1);
    level::Obstacle ob3(TESTFILE, 0, 0, 1, 1);
    std::vector<level::Obstacle*> vec1 = {&ob2, &ob3};

    col.add_obstacle_vector(vec1);

    ASSERT_EQ(col.obstacles_get().size(), 4);
}

TEST(CollisionHandler, add_obstacles_vector_empty_additive)
{
    level::Obstacle ob(TESTFILE, 0, 0, 1, 1);
    level::Obstacle ob1(TESTFILE, 0, 0, 1, 1);
    std::vector<level::Obstacle*> vec = {&ob, &ob1};
    level::CollisionHandler col(sf::Vector2u(10, 10), vec);

    std::vector<level::Obstacle*> vec1;

    col.add_obstacle_vector(vec1);

    ASSERT_EQ(col.obstacles_get().size(), 2);
}

TEST_P(ConstructorTests, Constructor_two_args)
{
    auto params = GetParam();

    level::CollisionHandler col(params.first, params.second);
    ASSERT_EQ(col.window_size_get(), params.first);
    ASSERT_EQ(col.obstacles_get().size(), params.second.size());
}

level::Obstacle ob(TESTFILE, 0, 0, 1, 1);
level::Obstacle ob1(TESTFILE, 0, 0, 1, 1);

std::vector<level::Obstacle*> vec = {&ob};
std::vector<level::Obstacle*> vec1 = {&ob, &ob1};

std::pair<sf::Vector2u, std::vector<level::Obstacle*>> p1(sf::Vector2u(1, 1), vec1);
std::pair<sf::Vector2u, std::vector<level::Obstacle*>> p2(sf::Vector2u(1, 1), vec);

INSTANTIATE_TEST_SUITE_P(CollisionHandler_tests, ConstructorTests,
        ::testing::Values (
            p1,
            p2
            ));

TEST_P(CheckTests, check)
{
    auto params = GetParam();
}


INSTANTIATE_TEST_SUITE_P(CollisionHandler_tests, CheckTests,
        ::testing::Values (
            ));
