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
    std::string compareBoard = "   +--+\n   | 1|\n+--+--+\n| 1|??|\n+--+--+\n";

    ASSERT_EQ(display(board), compareBoard);
}

TEST_F(DisplayBoardTests, checkDisplayBoard)
{
    Board board(1, 1, {{1}}, {{1}});
    std::string compareBoard = "   +--+\n   | 1|\n+--+--+\n| 1|??|\n+--+--+\n";

    testing::internal::CaptureStdout();
    board.display();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, compareBoard);
}

TEST_F(DisplayBoardTests, checkDisplayBoardWithClues)
{
    Board board(2, 2, {{1},{2}}, {{2},{1}});
    std::string compareBoard = "   +----+\n   | 2 1|\n+--+----+\n| 1|????|\n| 2|????|\n+--+----+\n";

    ASSERT_EQ(display(board), compareBoard);

    Board board2(3, 3, {{1},{},{2}}, {{2},{},{1}});
    compareBoard = "   +------+\n   | 2   1|\n+--+------+\n| 1|??????|\n|  |??????|\n| 2|??????|\n+--+------+\n";
    ASSERT_EQ(display(board2), compareBoard);

    Board board3(3, 3, {{},{1},{2}}, {{},{2},{1}});
    compareBoard = "   +------+\n   |   2 1|\n+--+------+\n|  |??????|\n| 1|??????|\n| 2|??????|\n+--+------+\n";
    ASSERT_EQ(display(board3), compareBoard);

    Board board4(3, 3, {{1},{2,1},{}}, {{2,1},{1},{}});
    compareBoard = "     +------+\n     | 1    |\n     | 2 1  |\n+----+------+\n|   1|??????|\n| 2 1|??????|\n|    |??????|\n+----+------+\n";
    ASSERT_EQ(display(board4), compareBoard);

    Board board5(3, 3, {{1},{1},{1,1}}, {{1},{},{1,1,1}});
    compareBoard = "     +------+\n     |     1|\n     |     1|\n     | 1   1|\n+----+------+\n|   1|??????|\n|   1|??????|\n| 1 1|??????|\n+----+------+\n";
    ASSERT_EQ(display(board5), compareBoard);
}
