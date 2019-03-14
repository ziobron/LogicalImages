#include "Board.hpp"
#include "json.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>
#include "DisplayBoard.hpp"
#include "JSONFileReader.hpp"

Board::Board(const unsigned int sizeRows,
             const unsigned int sizeCols,
             const Lines& cluesRows,
             const Lines& cluesCols) noexcept
    : sizeRows_(sizeRows),
      sizeCols_(sizeCols),
      cluesRows_(cluesRows),
      cluesCols_(cluesCols)
{
    BLine singleRow;
    singleRow.assign(sizeCols_, BoardFields::UNKNOWN);
    board_.assign(sizeRows_, singleRow);
}

Board::Board(std::string filename)
{
    JSONFileReader jfr(filename);
    sizeRows_ = jfr.readRowSize();
    sizeCols_ = jfr.readColSize();
    cluesRows_ = jfr.readCluesRows();
    cluesCols_ = jfr.readCluesCols();
    BLine singleRow;
    singleRow.assign(sizeCols_, BoardFields::UNKNOWN);
    board_.assign(sizeRows_, singleRow);
}

Board::~Board() {}

unsigned int Board::getSizeRows() const
{
    return sizeRows_;
}

unsigned int Board::getSizeCols() const
{
    return sizeCols_;
}

BLines Board::getBoardLines() const
{
    return board_;
}

unsigned int Board::getLongestLineLenght(const Lines& v) const
{
    auto it = std::max_element(v.begin(),
                               v.end(),
                               [](Line lhs, Line rhs){return lhs.size() < rhs.size();});
    return it->size();
}

unsigned int Board::getLongestCluesLenghtInRows() const
{
    return getLongestLineLenght(cluesRows_);
}

unsigned int Board::getLongestCluesLenghtInCols() const
{
    return getLongestLineLenght(cluesCols_);
}

void Board::display() const
{
    std::cout << DisplayBoard::display(*this);
}
