#include "Board.hpp"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

Board::Board(int rowNumber,
             int colNumber,
             const Lines& rows,
             const Lines& cols) noexcept
    : rowNumber_(rowNumber),
      colNumber_(colNumber),
      rows_(rows),
      cols_(cols)
{
    Line singleRow;
    singleRow.assign(colNumber_, 0);
    board_.assign(rowNumber_, singleRow);
}

int getRowNumberFromFile(std::string path)
{
    std::ifstream inputFile(path);
    json j;
    inputFile >> j;
    return j["rowNumber"];
}

int getColNumberFromFile(std::string path)
{
    std::ifstream inputFile(path);
    json j;
    inputFile >> j;
    return j["colNumber"];
}

Board::Board(std::string path)
    : rowNumber_(getRowNumberFromFile(path)),
      colNumber_(getColNumberFromFile(path))
{
    std::ifstream inputFile(path);
    json j;
    inputFile >> j;

    if ((rowNumber_ < 3) or (colNumber_ < 3))
        throw InvalidDimensions();

    Lines rows = j["rows"];
    Lines cols = j["cols"];
    rows_ = rows;
    cols_ = cols;

    Line singleRow;
    singleRow.assign(colNumber_, 0);
    board_.assign(rowNumber_, singleRow);
}

Board::~Board() {}
