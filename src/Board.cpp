#include "Board.hpp"
#include "json.hpp"
#include <fstream>
#include <algorithm>

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

int Board::findLongestVectorInLines(Lines &v) const
{
    auto it = std::max_element(v.begin(),
                               v.end(),
                               [](Line lhs, Line rhs){return lhs.size() < rhs.size();});
    return it->size();
}

int Board::findLongestVectorInRows()
{
    return findLongestVectorInLines(rows_);
}

int Board::findLongestVectorInCols()
{
    return findLongestVectorInLines(cols_);
}

std::stringstream Board::drawBoard()
{
    std::stringstream ss;
    const int widthRows = findLongestVectorInLines(rows_);
    const int heightCol = findLongestVectorInLines(cols_);
    std::string s = DisplayBoard::drawEndLine(widthRows);
    s.pop_back();

    ss << DisplayBoard::drawColumns(widthRows, colNumber_, heightCol);
    ss << s << DisplayBoard::drawEndLine(colNumber_) << "\n";
    for (int i = rowNumber_; i > 0 ; --i)
    {
        ss << DisplayBoard::drawRow(widthRows);
        ss << DisplayBoard::drawEmptyLine(colNumber_, '?') << "\n";
    }
    ss << s << DisplayBoard::drawEndLine(colNumber_);
    return ss;
}
