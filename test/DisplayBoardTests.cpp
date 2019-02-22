#include "DisplayBoard.hpp"
#include "json.hpp"
#include <gtest/gtest.h>

struct DisplayBoardTests : public ::testing::Test
{

};

TEST_F(DisplayBoardTests, checkDrawPaddingFor2Elements)
{
    std::string comparePad = "    ";
    std::string padding = drawPadding(2);
    ASSERT_EQ(padding,comparePad);
}
TEST_F(DisplayBoardTests, checkDrawEndLineFor2Element)
{
    std::string comparePad = "+----+";
    std::string endLine = drawEndLine(2);
    ASSERT_EQ(endLine,comparePad);
}
TEST_F(DisplayBoardTests, checkDrawEmptyLineFor2Element)
{
    std::string comparePad = "|    |";
    std::string emptyLine = drawEmptyLine(2);
    ASSERT_EQ(emptyLine, comparePad);
}

TEST_F(DisplayBoardTests, checkDrawingTable)
{
    std::string drawB = drawBoard(1,1).str();
    std::string compareBoard = "+--+\n|  |\n+--+";
    ASSERT_EQ(drawB,compareBoard);
}
