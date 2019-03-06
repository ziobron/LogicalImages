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

TEST_F(BoardTests, checkConstructorJSONFile)
{
    json j;
    j["col"] = {{1, 1}, {1}, {1}};
    j["row"] = {{1}, {1}, {1}};
    j["rowNum"] = 3;
    j["colNum"] = 3;

    ASSERT_ANY_THROW(Board board(j));
}
