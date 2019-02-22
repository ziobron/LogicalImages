#pragma once
#include "FieldsEnum.hpp"
#include "json.hpp"
#include "FieldsEnum.hpp"
#include <vector>
#include <iostream>
#include <sstream>

using Line = std::vector<int>;
using Lines = std::vector<Line>;
using BLine = std::vector<FieldsEnum>;
using BLines = std::vector<BLine>;

class Board
{
    const int rowNumber_;
    const int colNumber_;
    Lines rows_;
    Lines cols_;
    BLines board_;

public:
    Board(int rowNumber,
          int colNumber,
          const Lines& rows,
          const Lines& cols) noexcept;
    ~Board();

    int getRowsNumber() const;
    int getColsNumber() const;
    BLines getBoardLines() const;
    std::string drawPadding() const;
    std::string drawEndLine() const;
    std::string drawEmptyLine() const;
    std::stringstream drawBoard() const;

    const char HORIZONTAL = '-';
    const char VERTICAL = '|';
    const char INTERSECTION = '+';
    const char PADDING = ' ';
};

std::ostream & operator<<( std::ostream & stream, const Board & board);
