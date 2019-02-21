#pragma once
#include "json.hpp"
#include <vector>
#include <iostream>

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

    int getRowsNumber() const;
    int getColsNumber() const;
    std::string drawPadding(const int & el) const;
    std::string drawEndLine(const int & el) const;
    std::string drawEmptyLine(const int & el) const;
    std::string drawBoard(const int & rowNo, const int & colNo) const;

    const char HORIZONTAL = '-';
    const char VERTICAL = '|';
    const char INTERSECTION = '+';
    const char PADDING = ' ';
};

std::ostream & operator<<( std::ostream & stream, const Board & board);
