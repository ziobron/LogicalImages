#include "Board.hpp"
#include "json.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>
#include "DisplayBoard.hpp"

Board::Board(const unsigned int sizeRows,
             const unsigned int sizeCols,
             const Lines& rows,
             const Lines& cols) noexcept
    : sizeRows_(sizeRows),
      sizeCols_(sizeCols),
      rows_(rows),
      cols_(cols)
{
    BLine singleRow;
    singleRow.assign(sizeCols_, BoardFields::UNKNOWN);
    board_.assign(sizeRows_, singleRow);
}

Board::~Board() {}

unsigned int Board::getRowSize() const
{
    return sizeRows_;
}

unsigned int Board::getColSize() const
{
    return sizeCols_;
}

BLines Board::getBoardLines() const
{
    return board_;
}

unsigned int Board::getLongestLineLenght(const Lines& v) const
{
    auto it = std::max_element(v.begin(),
                               v.end(),
                               [](Line lhs, Line rhs){return lhs.size() < rhs.size();});
    return it->size();
}

unsigned int Board::getLongestRowLenght() const
{
    return getLongestLineLenght(rows_);
}

unsigned int Board::getLongestColLenght() const
{
    return getLongestLineLenght(cols_);
}

void Board::display() const
{
    std::cout << DisplayBoard::display(*this);
}
