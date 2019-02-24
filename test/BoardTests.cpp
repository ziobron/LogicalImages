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
    j["rowNum"] = 3;
    j["colNum"] = 2;

    Board board(j["rowNum"], j["colNum"], j["row"], j["col"]);
}

TEST_F(BoardTests, checkReadingJSON)
{
    std::string path = "../test/ReadMeBoardTestFile.json";
    JSONFileReader jfr(path);
    Board board(jfr.readRowsNumber(),
                jfr.readColsNumber(),
                jfr.readRows(),
                jfr.readCols());

    ASSERT_EQ(board.getRowsNumber(), 3);
    ASSERT_EQ(board.getColsNumber(), 3);
}

TEST_F(BoardTests, checkJSONFileReaderExceptions)
{
    std::string path;

    path = "../test/JSONFileReaderWrongColNumberTestFile.json";
    JSONFileReader jfr1(path);
    ASSERT_THROW(Board board(jfr1.readRowsNumber(),
                             jfr1.readColsNumber(),
                             jfr1.readRows(),
                             jfr1.readCols()), InvalidDimensions);

    path = "../test/JSONFileReaderWrongRowNumberTestFile.json";
    JSONFileReader jfr2(path);
    ASSERT_THROW(Board board(jfr2.readRowsNumber(),
                             jfr2.readColsNumber(),
                             jfr2.readRows(),
                             jfr2.readCols()), InvalidDimensions);

    path = "../test/JSONFileReaderNumberOfLinesAndColsNoMatch.json";
    JSONFileReader jfr3(path);
    ASSERT_THROW(Board board(jfr3.readRowsNumber(),
                             jfr3.readColsNumber(),
                             jfr3.readRows(),
                             jfr3.readCols()), InvalidDimensions);

    path = "../test/JSONFileReaderNumberOfLinesAndRowsNoMatch.json";
    JSONFileReader jfr4(path);
    ASSERT_THROW(Board board(jfr4.readRowsNumber(),
                             jfr4.readColsNumber(),
                             jfr4.readRows(),
                             jfr4.readCols()), InvalidDimensions);
}
TEST_F(BoardTests, checkBoardArgumentBoard_WithGetBoardLinesFunction)
{
    std::vector<int> vec = {1,2};
    std::vector<std::vector<int>> vec2 = {vec,vec};

    Board board(3, 3, vec2, vec2);
    ASSERT_EQ(board.getBoardLines().at(1)[1],FieldsEnum::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(1)[0],FieldsEnum::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(0)[1],FieldsEnum::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(0)[0],FieldsEnum::UNKNOWN);
}

TEST_F(BoardTests, functionGetMaxNumbEleInRowReturnsMaximumNumberOfElementsInRow)
{
    Board board(11,
                13,
                {{1},{3},{5},{7},{9},{11},{11},{11},{3,1,3},{3},{3},{5},{5}},
                {{3},{5},{6},{2,7},{4,7},{13},{4,7},{2,7},{6},{5},{3}});
    ASSERT_EQ(board.getMaxNumbEleInRow(),3);
}

TEST_F(BoardTests, functionGetMaxNumbEleInColReturnsMaximumNumberOfElementsInColumn)
{
    Board board(8,
                8,
                {{4},{6},{2,2,2},{8},{1,4,1},{2,2},{6},{4}},
                {{4},{3,2},{2,2,2},{2,5},{2,5},{2,2,2},{2,3},{4}});
    ASSERT_EQ(board.getMaxNumbEleInCol(),3);
}
