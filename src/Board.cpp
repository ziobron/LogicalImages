#include "Board.hpp"
//#include "json.hpp"
//#include "JSONFileReader.hpp"
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

Board::~Board() {}

int Board::getRowsNumber() const
{
    return rowNumber_;
}

int Board::getColsNumber() const
{
    return colNumber_;
}

std::string Board::drawPadding(const int & el) const
{
    std::string result;
    for (auto it = 0; it < el; it++)
        result += PADDING;
    return result;
}

std::string Board::drawEndLine(const int & el) const
{
    std::string result {INTERSECTION};
    for (auto it = 0; it < el; it++)
        result += HORIZONTAL;
    result += INTERSECTION;
    return result;
}

std::string Board::drawEmptyLine(const int & el) const
{
    std::string result {VERTICAL};
    for (auto it = 0; it < el; it++)
        result += PADDING;
    result += VERTICAL;
    return result;
}

std::string Board::drawBoard(const int & rowNo, const int & colNo) const
{
    std::string result;
    result += drawEndLine(colNo);
    result += "\n";
    for (auto it = 0; it < rowNo; it++)
    {
        result += drawEmptyLine(colNo);
        result += "\n";
    }
    drawEndLine(colNo);
    return result;
}

std::ostream & Board::operator<<( std::ostream & stream)
{
    return stream << drawBoard(rowNumber_, colNumber_);
}
