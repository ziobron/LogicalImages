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
    j["row_num"] = 3;
    j["col_num"] = 2;

    Board board(j["row_num"], j["col_num"], j["row"], j["col"]);
}
