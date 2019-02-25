#pragma once
#include "FieldsEnum.hpp"
#include "json.hpp"
#include <vector>
#include <iostream>
#include "DisplayBoard.hpp"

using Line = std::vector<int>;
using Lines = std::vector<Line>;
using BLine = std::vector<FieldsEnum>;
using BLines = std::vector<BLine>;

extern void foo();

class Board
{
    const int rowNumber_;
    const int colNumber_;
    Lines rows_;
    Lines cols_;
    BLines board_;
    int labelRowsWidth_;
    int labelColsWidth_;
    int checkLabelRowsWidth() const;
    int checkLabelColsHeight() const;

public:
    Board(int rowNumber,
          int colNumber,
          const Lines& rows,
          const Lines& cols) noexcept;
    ~Board();

    int getRowsNumber() const;
    int getColsNumber() const;
    BLines getBoardLines() const;

    int getLabelRowsWidth() const;
    int getLabelColsHeight() const;
    friend void DisplayBoard::foo(Board& b);
    void newDraw();

};

