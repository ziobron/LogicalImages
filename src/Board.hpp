#pragma once
#include <vector>

class Board
{
    const int row_number_, col_number_;
    std::vector<std::vector<int>> rows_;
    std::vector<std::vector<int>> cols_;
    std::vector<std::vector<int>> board_;

public:
    Board(int row_number, int col_number, std::vector<std::vector<int>> rows,
          std::vector<std::vector<int>> cols) noexcept;
    ~Board();
};
