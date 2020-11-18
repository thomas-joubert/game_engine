#include <SFML/System/Vector2.hpp>
#include <gtest/gtest.h>
#include <stdexcept>
#include <utility>

#include "object_tests.hh"

#include "../../src/object.hh"
#include "../../src/exceptions/unvalidpath.hh"

/// {
TEST_P(CtrObjectTesterBad, NegativeParameterIntConstructor)
{
    int *args = GetParam();
    ASSERT_THROW(Object(args[0], args[1], args[2], args[3]), std::invalid_argument);
}

int a[]{-1, -1, -1, -1};
int b[]{0, -1, -1, -1};
int c[]{1, 2, -1, -1};
int d[]{1, 2, 3, -1};
int e[]{-1, 2, 3, 4};

INSTANTIATE_TEST_SUITE_P(ObjectTests, CtrObjectTesterBad,
        ::testing::Values(
            a, b, c, d, e
        ));
/// }


/// {
TEST_P(CtrObjectTesterPairBad, NegativeParamaterPairConstructor)
{
    sf::Vector2f *args = CtrObjectTesterPairBad::GetParam();
    ASSERT_THROW(Object(args[0], args[1]), std::invalid_argument);
}

sf::Vector2f pa[]{{-1, -1}, {-1, -1}};
sf::Vector2f pb[]{{0, -1}, {-1, -1}};
sf::Vector2f pc[]{{1, 2}, {-1, -1}};
sf::Vector2f pd[]{{1, 2}, {3, -1}};
sf::Vector2f pe[]{{-1, 2}, {3, 4}};

INSTANTIATE_TEST_SUITE_P(ObjectTests, CtrObjectTesterPairBad,
        ::testing::Values(
            pa, pb, pc, pd, pe
        ));
/// }

/// {
TEST_P(CtrObjectTesterGood, validIntParameter)
{
    int *args = CtrObjectTesterGood::GetParam();
    Object ob(args[0], args[1], args[2], args[3]);

    ASSERT_EQ(ob.pos_x_get(), args[0]);
    ASSERT_EQ(ob.pos_y_get(), args[1]);
    ASSERT_EQ(ob.len_x_get(), args[2]);
    ASSERT_EQ(ob.len_y_get(), args[3]);

    ASSERT_EQ(ob.len_get(), sf::Vector2f(args[2], args[3]));
    ASSERT_EQ(ob.pos_get(), sf::Vector2f(args[0], args[1]));
}

int ga[]{1, 1, 1, 1};
int gb[]{0, 1, 1, 1};
int gc[]{1, 2, 1, 1};

INSTANTIATE_TEST_SUITE_P(ObjectTests, CtrObjectTesterGood,
        ::testing::Values(
            ga, gb, gc
     ));
/// }

/// {
TEST_P(CtrObjectTesterPairGood, validPairParameter)
{
    sf::Vector2f *args = CtrObjectTesterPairGood::GetParam();
    Object ob(args[0], args[1]);

    ASSERT_EQ(ob.pos_x_get(), args[0].x);
    ASSERT_EQ(ob.pos_y_get(), args[0].y);
    ASSERT_EQ(ob.len_x_get(), args[1].x);
    ASSERT_EQ(ob.len_y_get(), args[1].y);

    ASSERT_EQ(ob.len_get(), args[1]);
    ASSERT_EQ(ob.pos_get(), args[0]);
}

sf::Vector2f gpa[]{{1, 1}, {1, 1}};
sf::Vector2f gpb[]{{0, 1}, {1, 1}};
sf::Vector2f gpc[]{{1, 2}, {1, 1}};

INSTANTIATE_TEST_SUITE_P(ObjectTests, CtrObjectTesterPairGood,
        ::testing::Values(
            gpa, gpb, gpc
        ));
/// }
