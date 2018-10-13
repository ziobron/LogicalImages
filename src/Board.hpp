#pragma once
#include <vector>

using Line = std::vector<int>;
using Lines = std::vector<Line>;

class Board
{
    const int rowNumber_;
    const int colNumber_;
    Lines rows_;
    Lines cols_;
    Lines board_;

public:
    Board(int rowNumber,
          int colNumber,
          const Lines& rows,
          const Lines& cols) noexcept;
    ~Board();
};
