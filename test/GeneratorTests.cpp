#include <gtest/gtest.h>
#include "Generator.hpp"
#include <set>
#include <cmath>

struct GeneratorTests : public ::testing::Test
{
};

struct GeneratorParamTests : public ::testing::TestWithParam<std::tuple<int, int>>
{
};

TEST_F(GeneratorTests, checkConversionFromIntToBoardFields)
{
    Lines input = {{1, 1, 0},
                   {0, 1, 0}};
    BLines result = {{BoardFields::BLACK, BoardFields::BLACK, BoardFields::WHITE},
                     {BoardFields::WHITE, BoardFields::BLACK, BoardFields::WHITE}};

    ASSERT_EQ(result, ConvertIntToFieldEnum(input));
}

INSTANTIATE_TEST_CASE_P(Default,
                        GeneratorParamTests,
                        testing::Combine(testing::Range(3, 5),   // rows
                                         testing::Range(3, 5))); // cols

TEST_P(GeneratorParamTests, checkSizeOfAllPermutationForGivenBoard)
{
    int rows = std::get<0>(GetParam());
    int cols = std::get<1>(GetParam());

    auto result = GenerateAllBoardPermutations(rows, cols);
    std::set<Lines> s(result.begin(), result.end());

    ASSERT_EQ(s.size(), pow(2, (rows * cols)));
}
