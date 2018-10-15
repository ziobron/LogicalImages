#include "Board.hpp"
#include "json.hpp"
#include <gtest/gtest.h>
#include <fstream>

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
    std::ifstream i("../test/ReadMeBoardTestFile.json");
    json j;
    i >> j;

    Board board(j["rowNumber"], j["colNumber"], j["rows"], j["cols"]);
}
