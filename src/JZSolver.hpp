#include "Algorithm.hpp"

class JZSolver : Algorithm
{
    unsigned int stepCounter_ = 0;

    void verifyBoardClues(std::shared_ptr<Board> & b);
    void findAndFillCompleteLines(std::shared_ptr<Board> & b);

    BLine returnComleteBLineFromFullClues(Line clues);
public:
    bool solve(std::shared_ptr<Board> & b);
    unsigned int getStepCounter();
};
