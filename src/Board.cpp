#include "Board.hpp"
#include "json.hpp"
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
    BLine singleRow;
    singleRow.assign(colNumber_, FieldsEnum::UNKNOWN);
    board_.assign(rowNumber_, singleRow);
    drawBoard(3, 3);
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
    for (auto it = 0; it < (el * 2); it++)
        result += PADDING;
    return result;
}

std::string Board::drawEndLine(const int & el) const
{
    std::string result {INTERSECTION};
    for (auto it = 0; it < (el * 2); it++)
        result += HORIZONTAL;
    result += INTERSECTION;
    return result;
}

std::string Board::drawEmptyLine(const int & el) const
{
    std::string result {VERTICAL};
    for (auto it = 0; it < (el * 2); it++)
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
        result += drawEmptyLine(colNo) + "\n";

    result += drawEndLine(colNo);
    return result;
}

std::ostream & operator<<( std::ostream & stream, const Board & board)
{
    stream << board.drawBoard(board.getRowsNumber(), board.getColsNumber());
    return stream;
}
