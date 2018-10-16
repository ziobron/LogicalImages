#include "FieldsEnum.hpp"
#include <gtest/gtest.h>
#include <iostream>

class FieldsEnumTests :public ::testing::Test
{
public:
    FieldsEnum field;
};

TEST_F(FieldsEnumTests, assertCorrectWhiteField)
{
    field = FieldsEnum::WHITE;
    ASSERT_EQ(field, FieldsEnum::WHITE);
    ASSERT_EQ(static_cast<int>(field), ' ');
}
