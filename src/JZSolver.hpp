#include "Algorithm.hpp"

class JZSolver : Algorithm
{
    void verifyBoardClues(std::shared_ptr<Board> b);
public:
    bool solve(std::shared_ptr<Board> b);
};
