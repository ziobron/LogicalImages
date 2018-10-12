#include "Board.hpp"

Board::Board(int rowNumber,
             int colNumber,
             const Lines& rows,
             const Lines& cols) noexcept
    : rowNumber_(rowNumber),
      colNumber_(colNumber),
      rows_(rows),
      cols_(cols)
{
    Line singleRow;
    singleRow.assign(colNumber_, 0);
    board_.assign(rowNumber_, singleRow);
}

Board::~Board() {}
