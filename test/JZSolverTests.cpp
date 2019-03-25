#include <gtest/gtest.h>
#include "JZSolver.hpp"
#include <memory>

struct JZSolverTests : public ::testing::Test
{
    JZSolver solver;
};

TEST_F(JZSolverTests, checkJZSolverConstructor)
{
    Board board_col_err(
        4,
        3,
        {{1}, {3}, {1}, {1}},
        {{1, 1}, {2}, {2, 1}});
    Board board_row_err(
        4,
        3,
        {{1}, {3}, {1}, {1, 1}},
        {{1, 1}, {2}, {2}});
    Board board_col_count_err(
        4,
        3,
        {{1}, {3}, {1}, {1}},
        {{1, 1}, {2}});
    Board board_row_count_err(
        4,
        3,
        {{1}, {3}, {1}},
        {{1, 1}, {2}, {2}});
    Board board_ok(
        4,
        3,
        {{1}, {3}, {1}, {1}},
        {{1, 1}, {2}, {2}});

    auto board_col_err_ref = std::make_shared<Board>(board_col_err);
    auto board_row_err_ref = std::make_shared<Board>(board_row_err);
    auto board_col_count_err_ref = std::make_shared<Board>(board_col_count_err);
    auto board_row_count_err_ref = std::make_shared<Board>(board_row_count_err);
    auto board_ok_ref = std::make_shared<Board>(board_ok);
    
    ASSERT_THROW(solver.solve(board_col_err_ref), std::logic_error);
    ASSERT_THROW(solver.solve(board_row_err_ref), std::logic_error);
    ASSERT_THROW(solver.solve(board_col_count_err_ref), std::length_error);
    ASSERT_THROW(solver.solve(board_row_count_err_ref), std::length_error);
    ASSERT_NO_THROW(solver.solve(board_ok_ref));
}

TEST_F(JZSolverTests, checkSolvingBoardWithAllFullClueLines)
{
    auto board = std::make_shared<Board>(Board(5,
                                               3,
                                               {{3}, {1}, {1, 1}, {1}, {3}},
                                               {{1, 1, 1}, {2, 2}, {1, 1, 1}}));

    EXPECT_TRUE(solver.solve(board));
    EXPECT_EQ(solver.getStepCounter(), 0);
}
