#include "JZSolver.hpp"
#include <numeric>

bool JZSolver::solve(std::shared_ptr<Board> b)
{
    verifyBoardClues(b);

    return true;
}

void JZSolver::verifyBoardClues(std::shared_ptr<Board> b)
{
    if(b->getCluesCols().size() != b->getSizeCols())
        throw std::length_error("Invalid clues: some columns are missing clues.");

    if(b->getCluesRows().size() != b->getSizeRows())
        throw std::length_error("Invalid clues: some rows are missing clues.");

    unsigned int sum_rows = 0;
    unsigned int sum_cols = 0;

    for(auto row : b->getCluesRows())
    {
        sum_rows += std::accumulate(row.begin(), row.end(), 0);
    }

    for(auto col : b->getCluesCols())
    {
        sum_cols += std::accumulate(col.begin(), col.end(), 0);
    }

    if(sum_rows != sum_cols)
    {
        std::string msg = "Invalid clues: different object count in rows (which is " +
                          std::to_string(sum_rows) + ") and columns (which is " +
                          std::to_string(sum_cols) + ").";
        throw std::logic_error(msg);
    }
}
