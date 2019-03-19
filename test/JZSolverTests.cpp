#include <gtest/gtest.h>
#include "JZSolver.hpp"

struct JZSolverTests : public ::testing::Test
{
};

TEST_F(JZSolverTests, checkJZSolverConstructor)
{
    JZSolver solver();
}
