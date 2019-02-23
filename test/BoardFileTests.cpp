#include <gtest/gtest.h>
#include <string>
#include "Utilities.cpp"

struct BoardFileTests : public ::testing::Test
{
};

TEST_F(BoardFileTests, whenWrongDirectoryPathIsGiven)
{
    std::string path = "./WrongPath.txt";

    ASSERT_FALSE(loadFromFile(path));
}

TEST_F(BoardFileTests, whenEmptyFileIsGiven)
{
    std::string path = "./EmptyFile.txt";

    ASSERT_FALSE(loadFromFile(path));
}
