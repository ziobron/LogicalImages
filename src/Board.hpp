#pragma once
#include <vector>
#include <stdexcept>

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
    Board(std::string path);
    ~Board();
};

class InvalidDimensions : public std::invalid_argument
{
public:
    InvalidDimensions()
        : invalid_argument("Both dimensions must be at least 3")
    {}
};
