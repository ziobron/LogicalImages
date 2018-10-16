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


TEST_F(FieldsEnumTests, assertCorrectBlackField)
{
    field = FieldsEnum::BLACK;
    ASSERT_EQ(field, FieldsEnum::BLACK);
    ASSERT_EQ(static_cast<int>(field), '#');
}

TEST_F(FieldsEnumTests, assertCorrectUnknownField)
{
    field = FieldsEnum::UNKNOWN;
    ASSERT_EQ(field, FieldsEnum::UNKNOWN);
    ASSERT_EQ(static_cast<int>(field), '?');
}
