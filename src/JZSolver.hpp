#include "Algorithm.hpp"

#define DEBUG 1

class JZSolver : Algorithm
{
    void verifyBoardClues(std::shared_ptr<Board> b);
    void findAndFillCompleteLines(std::shared_ptr<Board> b);

    BLine returnComleteBLineFromFullClues(Line clues);
public:
    bool solve(std::shared_ptr<Board> b);
};
