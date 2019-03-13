#include "Board.hpp"
#include "json.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>
#include "DisplayBoard.hpp"

Board::Board(const unsigned int sizeRows,
             const unsigned int sizeCols,
             const Lines& cluesRows,
             const Lines& cluesCols) noexcept
    : sizeRows_(sizeRows),
      sizeCols_(sizeCols),
      cluesRows_(cluesRows),
      cluesCols_(cluesCols)
{
    BLine singleRow;
    singleRow.assign(sizeCols_, BoardFields::UNKNOWN);
    board_.assign(sizeRows_, singleRow);
}

Board::~Board() {}

unsigned int Board::getSizeRows() const
{
    return sizeRows_;
}

unsigned int Board::getSizeCols() const
{
    return sizeCols_;
}

BLines& Board::getBoardLines()
{
    return board_;
}

void Board::setField(unsigned int row, unsigned int col, BoardFields value)
{
    try
    {
        board_.at(row).at(col) = value;
    }
    catch(std::out_of_range const& ex)
    {
        std::cerr << "Dimensions ouf of range: " << ex.what() << std::endl;
        throw;
    }
}

void Board::setRow(unsigned int row, BLine values)
{
    try
    {
        if(board_.at(row).size() != values.size())
        {
            std::string msg = "input size (which is " + std::to_string(values.size()) +
                              ") have to be the same as row size (which is " +
                              std::to_string(board_.at(row).size()) + ")";
            throw std::out_of_range(msg);
        }

        for(int i = 0; i < values.size() ; i++)
            setField(row, i, values.at(i));
    }
    catch(std::out_of_range const& ex)
    {
        std::cerr << "Invalid dimensions: " << ex.what() << std::endl;
        throw;
    }
}

BoardFields Board::getField(unsigned int row, unsigned int col)
{
    try
    {
        return board_.at(row).at(col);
    }
    catch(std::out_of_range const& ex)
    {
        std::cerr << "Dimensions ouf of range: " << ex.what() << std::endl;
        throw;
    }
}

BLine Board::getRow(unsigned int row)
{
    try
    {
        return board_.at(row);
    }
    catch(std::out_of_range const& ex)
    {
        std::cerr << "Invalid dimensions: " << ex.what() << std::endl;
        throw;
    }
}

unsigned int Board::getLongestLineLenght(const Lines& v) const
{
    auto it = std::max_element(v.begin(),
                               v.end(),
                               [](Line lhs, Line rhs){return lhs.size() < rhs.size();});
    return it->size();
}

unsigned int Board::getLongestCluesLenghtInRows() const
{
    return getLongestLineLenght(cluesRows_);
}

unsigned int Board::getLongestCluesLenghtInCols() const
{
    return getLongestLineLenght(cluesCols_);
}

void Board::display() const
{
    std::cout << DisplayBoard::display(*this);
}
