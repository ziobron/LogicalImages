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
    j["cluesCols"] = {{1, 1}, {1}};
    j["cluesRows"] = {{1}, {1}, {1}};
    j["rowSize"] = 3;
    j["colSize"] = 2;

    Board board(j["rowSize"], j["colSize"], j["cluesRows"], j["cluesCols"]);
}

TEST_F(BoardTests, checkReadingJSON)
{
    std::string path = "../test/ReadMeBoardTestFile.json";
    JSONFileReader jfr(path);
    Board board(jfr.readRowSize(),
                jfr.readColSize(),
                jfr.readCluesRows(),
                jfr.readCluesCols());

    ASSERT_EQ(board.getSizeRows(), 3);
    ASSERT_EQ(board.getSizeCols(), 3);
}

TEST_F(BoardTests, checkJSONFileReaderExceptions)
{
    std::string path;

    path = "../test/JSONFileReaderWrongColSizeTestFile.json";
    JSONFileReader jfr1(path);
    ASSERT_THROW(Board board(jfr1.readRowSize(),
                             jfr1.readColSize(),
                             jfr1.readCluesRows(),
                             jfr1.readCluesCols()), InvalidDimensions);

    path = "../test/JSONFileReaderWrongRowSizeTestFile.json";
    JSONFileReader jfr2(path);
    ASSERT_THROW(Board board(jfr2.readRowSize(),
                             jfr2.readColSize(),
                             jfr2.readCluesRows(),
                             jfr2.readCluesCols()), InvalidDimensions);

    path = "../test/JSONFileReaderNumberOfLinesAndColsNoMatch.json";
    JSONFileReader jfr3(path);
    ASSERT_THROW(Board board(jfr3.readRowSize(),
                             jfr3.readColSize(),
                             jfr3.readCluesRows(),
                             jfr3.readCluesCols()), InvalidDimensions);

    path = "../test/JSONFileReaderNumberOfLinesAndRowsNoMatch.json";
    JSONFileReader jfr4(path);
    ASSERT_THROW(Board board(jfr4.readRowSize(),
                             jfr4.readColSize(),
                             jfr4.readCluesRows(),
                             jfr4.readCluesCols()), InvalidDimensions);
}
TEST_F(BoardTests, checkBoardArgumentBoard_WithGetBoardLinesFunction)
{
    Line vec = {1, 2};
    Lines vec2 = {vec, vec};

    Board board(3, 3, vec2, vec2);
    ASSERT_EQ(board.getBoardLines().at(1)[1], BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(1)[0], BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(0)[1], BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(0)[0], BoardFields::UNKNOWN);
}

TEST_F(BoardTests, checkBoardSetField)
{
    Board board(3, 2, {}, {});
    board.setField(0, 0, BoardFields::BLACK);
    board.setField(1, 0, BoardFields::WHITE);

    ASSERT_EQ(board.getBoardLines().at(0).at(0), BoardFields::BLACK);
    ASSERT_EQ(board.getBoardLines().at(1).at(1), BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(2).at(0), BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(0).at(1), BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(1).at(0), BoardFields::WHITE);
    ASSERT_EQ(board.getBoardLines().at(2).at(1), BoardFields::UNKNOWN);

    board.setField(0, 0, BoardFields::UNKNOWN);
    board.setField(2, 0, BoardFields::BLACK);
    board.setField(1, 0, BoardFields::UNKNOWN);
    board.setField(2, 1, BoardFields::WHITE);

    ASSERT_EQ(board.getBoardLines().at(0).at(0), BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(1).at(1), BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(2).at(0), BoardFields::BLACK);
    ASSERT_EQ(board.getBoardLines().at(0).at(1), BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(1).at(0), BoardFields::UNKNOWN);
    ASSERT_EQ(board.getBoardLines().at(2).at(1), BoardFields::WHITE);
}

TEST_F(BoardTests, checkBoardGetField)
{
    Board board(3, 2, {}, {});
    board.setField(0, 0, BoardFields::BLACK);
    board.setField(0, 1, BoardFields::WHITE);

    ASSERT_EQ(board.getField(1, 1), BoardFields::UNKNOWN);
    ASSERT_EQ(board.getField(1, 0), BoardFields::UNKNOWN);
    ASSERT_EQ(board.getField(0, 1), BoardFields::WHITE);
    ASSERT_EQ(board.getField(0, 0), BoardFields::BLACK);
}

TEST_F(BoardTests, checkBoardSetFieldException)
{
    Board board(2, 3, {}, {});
    ASSERT_THROW(board.setField(2, 0, BoardFields::BLACK), std::out_of_range);
    ASSERT_THROW(board.setField(0, 3, BoardFields::BLACK), std::out_of_range);
}

TEST_F(BoardTests, checkBoardGetFieldException)
{
    Board board(2, 3, {}, {});
    ASSERT_THROW(board.getField(2, 0), std::out_of_range);
    ASSERT_THROW(board.getField(0, 3), std::out_of_range);
}

TEST_F(BoardTests, checkBoardGetRow)
{
    Board board(3, 2, {}, {});
    BLine result1 = {BoardFields::BLACK, BoardFields::UNKNOWN};
    BLine result2 = {BoardFields::WHITE, BoardFields::UNKNOWN};

    board.setField(0, 0, BoardFields::BLACK);
    board.setField(1, 0, BoardFields::WHITE);

    ASSERT_EQ(board.getRow(0), result1);
    ASSERT_EQ(board.getRow(1), result2);
}

TEST_F(BoardTests, checkBoardSetRow)
{
    Board board(3, 2, {}, {});
    BLine result = {BoardFields::UNKNOWN, BoardFields::WHITE};

    board.setRow(1, result);
    ASSERT_EQ(board.getRow(1), result);
}

TEST_F(BoardTests, checkBoardGetRowException)
{
    Board board(2, 4, {}, {});
    ASSERT_THROW(board.getRow(3), std::out_of_range);
}

TEST_F(BoardTests, checkBoardSetRowException)
{
    Board board(2, 4, {}, {});
    BLine lineTooBig = {BoardFields::UNKNOWN, BoardFields::WHITE, BoardFields::UNKNOWN};
    BLine lineTooShort = {BoardFields::UNKNOWN};
    BLine lineGood = {BoardFields::UNKNOWN, BoardFields::WHITE};

    ASSERT_THROW(board.setRow(1, lineTooBig), std::out_of_range);
    ASSERT_THROW(board.setRow(1, lineTooShort), std::out_of_range);
    ASSERT_THROW(board.setRow(3, lineGood), std::out_of_range);
}

TEST_F(BoardTests, findLongestVectorLenghtOfCluesInRows)
{
    Board board(4,
                5,
                {{1}, {1, 2}, {1, 2, 3, 4}, {1, 2, 3}},
                {{1}, {1, 2, 3, 4 ,5}, {1}, {1, 2}, {1}});
    ASSERT_EQ(board.getLongestCluesLenghtInRows(), 4);
}

TEST_F(BoardTests, findLongestVectorLenghtOfCluesInCols)
{
    Board board(4,
                5,
                {{1}, {1, 2}, {1, 2, 3, 4}, {1, 2, 3}},
                {{1}, {1, 2, 3, 4 ,5}, {1}, {1, 2}, {1}});
    ASSERT_EQ(board.getLongestCluesLenghtInCols(), 5);
}
