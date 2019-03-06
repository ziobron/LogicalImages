#pragma once
#include "json.hpp"
#include "FieldsEnum.hpp"
#include <vector>

using Line = std::vector<int>;
using Lines = std::vector<Line>;
using BLine = std::vector<FieldsEnum>;
using BLines = std::vector<BLine>;
using json = nlohmann::json;

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
    Board(std::string filename);
    ~Board();

    int getRowsNumber() const;
    int getColsNumber() const;
    json getJson() const;
};
