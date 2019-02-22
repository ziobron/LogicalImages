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

BLines Board::getBoardLines() const
{
    return board_;
}

std::string Board::drawPadding() const
{
    std::string result;
    for (auto it = 0; it < (colNumber_ * 2); it++)
        result += PADDING;
    return result;
}

std::string Board::drawEndLine() const
{
    std::string result {INTERSECTION};
    for (auto it = 0; it < (colNumber_ *2); it++)
        result += HORIZONTAL;
    result += INTERSECTION;
    return result;
}

std::string Board::drawEmptyLine() const
{
    std::string result {VERTICAL};
    for (auto it = 0; it < (colNumber_ * 2); it++)
        result += PADDING;
    result += VERTICAL;
    return result;
}

std::stringstream Board::drawBoard() const
{
    std::stringstream s;
    s << drawEndLine() << std::endl;
    for (int i = rowNumber_;i > 0 ; --i){
        s << drawEmptyLine() << std::endl;
    }
    s << drawEndLine();
    return  s;
}
