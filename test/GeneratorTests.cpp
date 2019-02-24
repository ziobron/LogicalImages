#include <gtest/gtest.h>
#include "Generator.hpp"
#include <set>
#include <cmath>

struct GeneratorTests : public ::testing::Test
{
};

TEST_F(GeneratorTests, checkConversionFromIntToFieldsEnum)
{
    Lines input = {{1, 1, 0},
                   {0, 1, 0}};
    BLines result = {{FieldsEnum::BLACK, FieldsEnum::BLACK, FieldsEnum::WHITE},
                     {FieldsEnum::WHITE, FieldsEnum::BLACK, FieldsEnum::WHITE}};

    ASSERT_EQ(result, ConvertIntToFieldEnum(input));
}

TEST_F(GeneratorTests, checkSizeOfSAllPermutationOfBoard2x3)
{
    int rows = 2;
    int cols = 3;
    auto result = GenerateAllBoardPermutations(rows,cols);
    std::set<Lines> s(result.begin(), result.end());
    ASSERT_EQ(s.size(), pow(2,(rows * cols)));
}

TEST_F(GeneratorTests, checkSizeOfSAllPermutationOfBoard4x3)
{
    int rows = 4;
    int cols = 3;
    auto result = GenerateAllBoardPermutations(rows,cols);
    std::set<Lines> s(result.begin(), result.end());
    ASSERT_EQ(s.size(), pow(2,(rows * cols)));
}
