#include "Board.hpp"
#include "json.hpp"
#include "JSONFileReader.hpp"
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
{
    JSONFileReader fileReader(path);

    if ((fileReader.readRowsNumber() < 3) or (fileReader.readColsNumber() < 3))
        throw InvalidDimensions("Both dimensions must be at least 3");
    else if ((fileReader.readRowsNumber() != fileReader.readRows().size()) or
             (fileReader.readColsNumber() != fileReader.readCols().size()))
        throw InvalidDimensions("Number of lines is different than rows or cols");

    rowNumber_ = fileReader.readRowsNumber();
    colNumber_ = fileReader.readColsNumber();

    rows_ = fileReader.readRows();
    cols_ = fileReader.readCols();

    Line singleRow;
    singleRow.assign(colNumber_, 0);
    board_.assign(rowNumber_, singleRow);
}

Board::~Board() {}

int Board::getRowsNumber() const
{
    return rowNumber_;
}

int Board::getColsNumber() const
{
    return colNumber_;
}
