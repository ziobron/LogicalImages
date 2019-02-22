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

TEST_F(GeneratorTests, checkConversionFromIntToFieldsEnum)
{
    Lines input = {{1, 1, 0},
                   {0, 1, 0}};
    BLines result = {{FieldsEnum::BLACK, FieldsEnum::BLACK, FieldsEnum::WHITE},
                     {FieldsEnum::WHITE, FieldsEnum::BLACK, FieldsEnum::WHITE}};

    ASSERT_EQ(result, ConvertIntToFieldEnum(input));
}
