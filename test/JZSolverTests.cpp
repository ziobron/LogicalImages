#include <gtest/gtest.h>
#include "JZSolver.hpp"

struct JZSolverTests : public ::testing::Test
{
    JZSolver solver;
};

TEST_F(JZSolverTests, checkJZSolverConstructor)
{
    Board board_col_err(4,
                        3,
                        {{1}, {3}, {1}, {1}},
                        {{1, 1}, {2}, {2, 1}});
    Board board_row_err(4,
                        3,
                        {{1}, {3}, {1}, {1, 1}},
                        {{1, 1}, {2}, {2}});
    Board board_col_count_err(4,
                              3,
                              {{1}, {3}, {1}, {1}},
                              {{1, 1}, {2}});
    Board board_row_count_err(4,
                              3,
                              {{1}, {3}, {1}},
                              {{1, 1}, {2}, {2}});
    Board board_ok(4,
                   3,
                   {{1}, {3}, {1}, {1}},
                   {{1, 1}, {2}, {2}});

    ASSERT_THROW(solver.solve(std::make_shared<Board>(board_col_err)), std::logic_error);
    ASSERT_THROW(solver.solve(std::make_shared<Board>(board_row_err)), std::logic_error);
    ASSERT_THROW(solver.solve(std::make_shared<Board>(board_col_count_err)), std::length_error);
    ASSERT_THROW(solver.solve(std::make_shared<Board>(board_row_count_err)), std::length_error);
    ASSERT_NO_THROW(solver.solve(std::make_shared<Board>(board_ok)));
}