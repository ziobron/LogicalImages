#include "Board.hpp"
#include "json.hpp"
#include <fstream>
#include <algorithm>
#include "DisplayBoard.hpp"

Board::Board(const unsigned int rowNumber,
             const unsigned int colNumber,
             const Lines& rows,
             const Lines& cols) noexcept
    : rowNumber_(rowNumber),
      colNumber_(colNumber),
      rows_(rows),
      cols_(cols)
{
    BLine singleRow;
    singleRow.assign(colNumber_, FieldsEnum::UNKNOWN);
    board_.assign(rowNumber_, singleRow);
}

Board::~Board() {}

unsigned int Board::getRowsNumber() const
{
    return rowNumber_;
}

unsigned int Board::getColsNumber() const
{
    return colNumber_;
}

BLines Board::getBoardLines() const
{
    return board_;
}

unsigned int Board::findLongestVectorInLines(const Lines& v) const
{
    auto it = std::max_element(v.begin(),
                               v.end(),
                               [](Line lhs, Line rhs){return lhs.size() < rhs.size();});
    return it->size();
}

unsigned int Board::findLongestVectorInRows() const
{
    return findLongestVectorInLines(rows_);
}

unsigned int Board::findLongestVectorInCols() const
{
    return findLongestVectorInLines(cols_);
}

void Board::display() const
{
    auto tmp = DisplayBoard::displayInterface(*this);
    std::cout << tmp << "\n";
}
