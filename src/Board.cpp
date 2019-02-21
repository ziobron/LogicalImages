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
    drawBoard(board_);
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

std::string Board::drawPadding(const int & numberOfElements) const
{
    std::string result;
    for (auto it = 0; it < (numberOfElements * 2); it++)
        result += PADDING;
    return result;
}

std::string Board::drawEndLine(const int & numberOfElements) const
{
    std::string result {INTERSECTION};
    for (auto it = 0; it < numberOfElements; it++)
        result += HORIZONTAL;
    result += INTERSECTION;
    return result;
}

std::string Board::drawEmptyLine(const int & numberOfElements) const
{
    std::string result {VERTICAL};
    for (auto it = 0; it < numberOfElements; it++)
        result += PADDING;
    result += VERTICAL;
    return result;
}

void Board::drawBoard(const auto & board) const
{
    std::cout << drawEndLine(sizeof(board));
    std::cout << "\n";
    for (const auto & it : board[0]){
        std::cout << drawEmptyLine(sizeof(board));
        std::cout << "\n";
    }
    std::cout << drawEndLine(sizeof(board));
}
