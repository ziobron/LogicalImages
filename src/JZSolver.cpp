#include "JZSolver.hpp"
#include <numeric>
#include <iostream>

bool JZSolver::solve(std::shared_ptr<Board> b)
{
    verifyBoardClues(b);
    findAndFillCompleteLines(b);
    return true;
}

void JZSolver::verifyBoardClues(std::shared_ptr<Board> b)
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

void JZSolver::findAndFillCompleteLines(std::shared_ptr<Board> b)
{
#if DEBUG
    unsigned int lineCounter = 0;
#endif
    for(int rowCnt = 0; rowCnt < b->getSizeRows(); rowCnt++)
    {
        auto row =  b->getCluesRows()[rowCnt];
        unsigned int cluesResult = std::accumulate(row.begin(), row.end(), 0) + row.size() - 1;

        if(b->getSizeCols() == cluesResult)
        {
            b->setRow(rowCnt, returnComleteBLineFromFullClues(row));
#if DEBUG
            lineCounter++;
#endif
        }
    }

    for(int colCnt = 0; colCnt < b->getSizeCols(); colCnt++)
    {
        auto col =  b->getCluesCols()[colCnt];
        unsigned int cluesResult = std::accumulate(col.begin(), col.end(), 0) + col.size() - 1;

        if(b->getSizeRows() == cluesResult)
        {
            b->setCol(colCnt, returnComleteBLineFromFullClues(col));
#if DEBUG
            lineCounter++;
#endif
        }
    }
#if DEBUG
    std::cout << "findAndFillCompleteLines: " << lineCounter << " complete lines found in clues" << std::endl;
    //b->display();
    b->show();
#endif
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
