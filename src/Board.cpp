#include "Board.hpp"
#include "json.hpp"
#include "JSONFileReader.hpp"
#include <fstream>

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

Board::Board(std::string filename)
    : rowNumber_(JSONFileReader(filename).readRowsNumber()),
    colNumber_(JSONFileReader(filename).readColsNumber()),
    rows_(JSONFileReader(filename).readRows()),
    cols_(JSONFileReader(filename).readCols())
{
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

json Board::getJson() const
{
    json j;

    j["rowNumber"] = rowNumber_;
    j["colNumber"] = colNumber_;
    j["rows"] = rows_;
    j["cols"] = cols_;

    return j;
}
