#include <gtest/gtest.h>

#include <stdexcept>
#include <utility>
#include <exception>

class CoordinatesCheckTest : public testing::TestWithParam<int*>
{};
