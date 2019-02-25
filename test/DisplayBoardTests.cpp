//added for testing private methods
//acccording to google test guide
#include "DisplayBoard.cpp"
#include "json.hpp"
#include <gtest/gtest.h>

struct DisplayBoardTests : public ::testing::Test
{
};

TEST_F(DisplayBoardTests, checkDrawPaddingFor2Elements)
{
    std::string comparePad = "    ";
    std::string padding = drawPadding(2);

    ASSERT_EQ(padding, comparePad);
}

TEST_F(DisplayBoardTests, checkDrawEndLineFor2Element)
{
    std::string comparePad = "+----+";
    std::string endLine = drawEndLine(2);

    ASSERT_EQ(endLine, comparePad);
}

TEST_F(DisplayBoardTests, checkDrawEmptyLineFor2Element)
{
    std::string comparePad = "|    |";
    std::string emptyLine = drawEmptyLine(2);

    ASSERT_EQ(emptyLine, comparePad);
}

TEST_F(DisplayBoardTests, checkDrawingEmptyColumnsForHeightOne)
{
    std::string compareColumns = "     +----+\n     |    |\n";
    std::string drawCol = drawColumns(2, 2, 1);

    ASSERT_EQ(compareColumns, drawCol);
}

TEST_F(DisplayBoardTests, checkDrawingEmptyColumnsForHeightTwo)
{
    std::string compareColumns = "     +----+\n     |    |\n     |    |\n";
    std::string drawCol = drawColumns(2, 2, 2);

    ASSERT_EQ(compareColumns, drawCol);
}

TEST_F(DisplayBoardTests, checkDrawingEmptyRowsForMaxOneElementInRow)
{
    std::string compareRow = "|  ";
    std::string drawR = drawRow(1);

    ASSERT_EQ(drawR, compareRow);
}

TEST_F(DisplayBoardTests, checkDrawingEmptyTable3x3)
{
    Board board(3, 3, {{}}, {{}});
    std::string compareBoard = " +------+\n++------+\n||??????|\n||??????|\n||??????|\n++------+";

    ASSERT_EQ(DB::displayInterface(board), compareBoard);
}

TEST_F(DisplayBoardTests, checkDrawingTable)
{
    Board board(1, 1, {{1}}, {{1}});
    std::string compareBoard = "   +--+\n   |  |\n+--+--+\n|  |??|\n+--+--+";

    ASSERT_EQ(DB::displayInterface(board), compareBoard);
}
