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

    int getMaxNumbEleInRow() const;
    int getMaxNumbEleInCol() const;
    friend std::stringstream DisplayBoard::drawBoard(const int width,
                                                     const int height,
                                                     const int widthRows,
                                                     const int heightCol);
};

