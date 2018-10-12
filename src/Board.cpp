#include "Board.hpp"

Board::Board(int row_number, int col_number,
             const std::vector<std::vector<int>> &rows,
             const std::vector<std::vector<int>> &cols) noexcept
    : row_number_(row_number),
      col_number_(col_number),
      rows_(rows),
      cols_(cols)
{
    std::vector<int> single_row;
    single_row.assign(col_number_, 0);
    board_.assign(row_number_, single_row);
}

Board::~Board() {}
