#include "JZSolver.hpp"
#include <numeric>
#include <iostream>

bool JZSolver::solve(std::shared_ptr<Board> & b)
{
    verifyBoardClues(b);
    findAndFillCompleteLines(b);

    while(not b->isSolved())
    {
        stepCounter_++;
        // methods to solve puzzle
        // if method changes something at board then start loop from beginning
        // if all methods haven't changed anything then break loop and admit failure
        break;
    }
    return b->isSolved();
}

unsigned int JZSolver::getStepCounter()
{
    return stepCounter_;
}

void JZSolver::verifyBoardClues(std::shared_ptr<Board> & b)
{
    if(b->getCluesCols().size() != b->getSizeCols())
        throw std::length_error("Invalid clues: some columns are missing clues.");

    if(b->getCluesRows().size() != b->getSizeRows())
        throw std::length_error("Invalid clues: some rows are missing clues.");

    unsigned int sumRows = 0;
    unsigned int sumCols = 0;

    for(auto row : b->getCluesRows())
    {
        sumRows += std::accumulate(row.begin(), row.end(), 0);
    }

    for(auto col : b->getCluesCols())
    {
        sumCols += std::accumulate(col.begin(), col.end(), 0);
    }

    if(sumRows != sumCols)
    {
        std::string msg = "Invalid clues: different object count in rows (which is " +
                          std::to_string(sumRows) + ") and columns (which is " +
                          std::to_string(sumCols) + ").";
        throw std::logic_error(msg);
    }
}

void JZSolver::findAndFillCompleteLines(std::shared_ptr<Board> & b)
{
    for(int rowCnt = 0; rowCnt < b->getSizeRows(); rowCnt++)
    {
        auto row =  b->getCluesRows()[rowCnt];
        auto spaces = row.size() - 1;
        unsigned int cluesResult = std::accumulate(row.begin(), row.end(), 0) + spaces;

        if(b->getSizeCols() == cluesResult)
        {
            b->setRow(rowCnt, returnComleteBLineFromFullClues(row));
        }
    }

    for(int colCnt = 0; colCnt < b->getSizeCols(); colCnt++)
    {
        auto col =  b->getCluesCols()[colCnt];
        unsigned int cluesResult = std::accumulate(col.begin(), col.end(), 0) + col.size() - 1;

        if(b->getSizeRows() == cluesResult)
        {
            b->setCol(colCnt, returnComleteBLineFromFullClues(col));
        }
    }
}

BLine JZSolver::returnComleteBLineFromFullClues(Line clues)
{
    BLine result;

    for(int elem = 0; elem < clues.size(); elem++)
    {
        for(int i = 0; i < clues[elem]; i++)
            result.emplace_back(BoardFields::BLACK);
        if(elem != (clues.size() - 1))
            result.emplace_back(BoardFields::WHITE);
    }
    return result;
}
