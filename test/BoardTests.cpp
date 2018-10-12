#include "Board.hpp"
#include "json.hpp"
#include <gtest/gtest.h>

struct BoardTests : public ::testing::Test
{
};

TEST_F(BoardTests, checkConstructorNoexception)
{
    nlohmann::json j;
    j["col"] = {{1, 1}, {1}};
    j["row"] = {{1}, {1}, {1}};
    j["rowNum"] = 3;
    j["colNum"] = 2;

    Board board(j["rowNum"], j["colNum"], j["row"], j["col"]);
}
