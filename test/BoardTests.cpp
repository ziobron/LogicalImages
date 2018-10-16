#include "Board.hpp"
#include "json.hpp"
#include <gtest/gtest.h>

struct BoardTests : public ::testing::Test
{
    using json = nlohmann::json;
};

TEST_F(BoardTests, checkConstructorNoexception)
{
    json j;
    j["col"] = {{1, 1}, {1}};
    j["row"] = {{1}, {1}, {1}};
    j["rowNum"] = 3;
    j["colNum"] = 2;

    Board board(j["rowNum"], j["colNum"], j["row"], j["col"]);
}

TEST_F(BoardTests, checkReadingJSON)
{
    Board board("../test/ReadMeBoardTestFile.json");

    ASSERT_EQ(board.getRowsNumber(), 3);
    ASSERT_EQ(board.getColsNumber(), 3);
}
