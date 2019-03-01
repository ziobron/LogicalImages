#include "json.hpp"
#include <gtest/gtest.h>
#include "DisplayBoard.hpp"

using namespace DisplayBoard;

struct DisplayBoardTests : public ::testing::Test
{
};

TEST_F(DisplayBoardTests, checkDrawingEmptyTable3x3)
{
    Board board(3, 3, {{}}, {{}});
    std::string compareBoard = " +------+\n++------+\n||??????|\n||??????|\n||??????|\n++------+\n";

    ASSERT_EQ(display(board), compareBoard);
}

TEST_F(DisplayBoardTests, checkDrawingTable)
{
    Board board(1, 1, {{1}}, {{1}});
    std::string compareBoard = "   +--+\n   |  |\n+--+--+\n|  |??|\n+--+--+\n";

    ASSERT_EQ(display(board), compareBoard);
}

TEST_F(DisplayBoardTests, checkDisplayBoard)
{
    Board board(1, 1, {{1}}, {{1}});
    std::string compareBoard = "   +--+\n   |  |\n+--+--+\n|  |??|\n+--+--+\n";

    ASSERT_EQ(display(board), compareBoard);
}
