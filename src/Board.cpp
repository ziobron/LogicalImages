#include "Board.hpp"
#include "json.hpp"
//#include "JSONFileReader.hpp"
#include <fstream>
#include <algorithm>
#include "DisplayBoard.hpp"

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
    labelColsWidth_ = checkLabelColsHeight();
    labelRowsWidth_ = checkLabelRowsWidth();
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

int Board::checkLabelRowsWidth() const
{
    auto it = std::max_element(rows_.begin(),
                               rows_.end(),
                               [](Line lhs, Line rhs){
            return lhs.size() < rhs.size();});
    return it->size();
}

int Board::checkLabelColsHeight() const
{
    auto it = std::max_element(cols_.begin(),
                               cols_.end(),
                               [](Line lhs, Line rhs){
            return lhs.size() < rhs.size();});
    return it->size();
}

int Board::getLabelRowsWidth() const
{
    return labelRowsWidth_;
}

int Board::getLabelColsHeight() const
{
    return labelColsWidth_;
}

void Board::display() const
{
    DisplayBoard::displayInterface(*this);
}
