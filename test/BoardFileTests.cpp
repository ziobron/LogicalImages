#include <gtest/gtest.h>
#include <string>
#include "Utilities.cpp"

struct BoardFileTests : public ::testing::Test
{
};

TEST_F(BoardFileTests, whenFileToReadPathIsGiven)
{
    std::string path = "./EmptyFile.txt";

    ASSERT_NO_THROW(openFileToRead(path));
}

TEST_F(BoardFileTests, whenWrongFileToReadPathIsGiven)
{
    std::string path = "./WrongPath.txt";

    ASSERT_ANY_THROW(openFileToRead(path));
}




