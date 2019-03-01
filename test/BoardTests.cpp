#include "Board.hpp"
#include "JSONFileReader.hpp"
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
    j["rowSize"] = 3;
    j["colSize"] = 2;

    Board board(j["rowSize"], j["colSize"], j["row"], j["col"]);
}

TEST_F(BoardTests, checkReadingJSON)
{
    std::string path = "../test/ReadMeBoardTestFile.json";
    JSONFileReader jfr(path);
    Board board(jfr.readRowSize(),
                jfr.readColSize(),
                jfr.readRows(),
                jfr.readCols());

    ASSERT_EQ(board.getRowSize(), 3);
    ASSERT_EQ(board.getColSize(), 3);
}

TEST_F(BoardTests, checkJSONFileReaderExceptions)
{
    std::string path;

    path = "../test/JSONFileReaderWrongColSizeTestFile.json";
    JSONFileReader jfr1(path);
    ASSERT_THROW(Board board(jfr1.readRowSize(),
                             jfr1.readColSize(),
                             jfr1.readRows(),
                             jfr1.readCols()), InvalidDimensions);

    path = "../test/JSONFileReaderWrongRowSizeTestFile.json";
    JSONFileReader jfr2(path);
    ASSERT_THROW(Board board(jfr2.readRowSize(),
                             jfr2.readColSize(),
                             jfr2.readRows(),
                             jfr2.readCols()), InvalidDimensions);

    path = "../test/JSONFileReaderNumberOfLinesAndColsNoMatch.json";
    JSONFileReader jfr3(path);
    ASSERT_THROW(Board board(jfr3.readRowSize(),
                             jfr3.readColSize(),
                             jfr3.readRows(),
                             jfr3.readCols()), InvalidDimensions);

    path = "../test/JSONFileReaderNumberOfLinesAndRowsNoMatch.json";
    JSONFileReader jfr4(path);
    ASSERT_THROW(Board board(jfr4.readRowSize(),
                             jfr4.readColSize(),
                             jfr4.readRows(),
                             jfr4.readCols()), InvalidDimensions);
}
TEST_F(BoardTests, checkBoardArgumentBoard_WithGetBoardLinesFunction)
{
    Line vec = {1, 2};
    Lines vec2 = {vec, vec};

    Board board(3, 3, vec2, vec2);
    ASSERT_EQ(board.getBoardLines().at(1)[1],BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(1)[0],BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(0)[1],BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(0)[0],BoardFields::UNKNOWN);
}

TEST_F(BoardTests, findLongestVectorOfCluesInRows)
{
    Board board(4,
                5,
                {{1}, {1, 2}, {1, 2, 3, 4}, {1, 2, 3}},
                {{1}, {1, 2, 3, 4 ,5}, {1}, {1, 2}, {1}});
    ASSERT_EQ(board.getLongestRowLenght(), 4);
}

TEST_F(BoardTests, findLongestVectorOfCluesInCols)
{
    Board board(4,
                5,
                {{1}, {1, 2}, {1, 2, 3, 4}, {1, 2, 3}},
                {{1}, {1, 2, 3, 4 ,5}, {1}, {1, 2}, {1}});
    ASSERT_EQ(board.getLongestColLenght(), 5);
}
