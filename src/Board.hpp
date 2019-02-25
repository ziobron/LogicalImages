#pragma once
#include "FieldsEnum.hpp"
#include "json.hpp"
#include <vector>
#include <iostream>

using u_int = unsigned int;
using Line = std::vector<int>;
using Lines = std::vector<Line>;
using BLine = std::vector<FieldsEnum>;
using BLines = std::vector<BLine>;

class Board
{
    const u_int rowNumber_;
    const u_int colNumber_;
    Lines rows_;
    Lines cols_;
    BLines board_;

public:
    Board(const u_int rowNumber,
          const u_int colNumber,
          const Lines& rows,
          const Lines& cols) noexcept;
    ~Board();

    u_int getRowsNumber() const;
    u_int getColsNumber() const;
    BLines getBoardLines() const;

    u_int findLongestVectorInLines(const Lines& v) const;
    u_int findLongestVectorInRows() const;
    u_int findLongestVectorInCols() const;

    void display() const;
};
