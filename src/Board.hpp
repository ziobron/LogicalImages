#pragma once
#include "BoardFields.hpp"
#include "json.hpp"
#include <vector>

using Line = std::vector<int>;
using Lines = std::vector<Line>;
using BLine = std::vector<BoardFields>;
using BLines = std::vector<BLine>;

class Board
{
    const unsigned int rowNumber_;
    const unsigned int colNumber_;
    Lines rows_;
    Lines cols_;
    BLines board_;

public:
    Board(const unsigned int rowNumber,
          const unsigned int colNumber,
          const Lines& rows,
          const Lines& cols) noexcept;
    ~Board();

    unsigned int getRowsNumber() const;
    unsigned int getColsNumber() const;
    BLines getBoardLines() const;

    unsigned int getLongestLineLenght(const Lines& v) const;
    unsigned int getLongestRowLenght() const;
    unsigned int getLongestColLenght() const;

    void display() const;
};
