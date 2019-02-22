#include <gtest/gtest.h>
#include "Generator.hpp"
#include <set>
#include <cmath>

struct GeneratorTests : public ::testing::Test
{
};

TEST_F(GeneratorTests, checkSizeOfSAllPermutationOfSingleVector)
{
    auto result = getAllVectorPermutation_(3);
    std::set<Line> s(result.begin(), result.end());
    ASSERT_EQ(s.size(), pow(2,3));
}
