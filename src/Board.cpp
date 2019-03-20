#include "Board.hpp"
#include "json.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>
#include "DisplayBoard.hpp"

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

Board::~Board() {}

unsigned int Board::getSizeRows() const
{
    return sizeRows_;
}

unsigned int Board::getSizeCols() const
{
    return sizeCols_;
}

BLines& Board::getBoardLines()
{
    return board_;
}

void Board::setField(unsigned int row, unsigned int col, BoardFields value) try
{
    board_.at(row).at(col) = value;
}
catch(std::out_of_range const& ex)
{
    std::cerr << "Dimensions ouf of range: " << ex.what() << std::endl;
    throw;
}

void Board::setRow(unsigned int row, BLine values) try
{
    if(sizeCols_ != values.size())
    {
        std::string msg = "input size (which is " + std::to_string(values.size()) +
                          ") have to be the same as row size (which is " +
                          std::to_string(sizeCols_) + ")";
        throw std::out_of_range(msg);
    }

    for(int i = 0; i < sizeCols_; i++)
        setField(row, i, values.at(i));
}
catch(std::out_of_range const& ex)
{
    std::cerr << "Invalid dimensions: " << ex.what() << std::endl;
    throw;
}

void Board::setCol(unsigned int col, BLine values) try
{
    if(sizeRows_ != values.size())
    {
        std::string msg = "input size (which is " + std::to_string(values.size()) +
                          ") have to be the same as column size (which is " +
                          std::to_string(sizeRows_) + ")";
        throw std::out_of_range(msg);
    }

    for(int i = 0; i < sizeRows_; i++)
        setField(i, col, values.at(i));
}
catch(std::out_of_range const& ex)
{
    std::cerr << "Invalid dimensions (setCol): " << ex.what() << std::endl;
    throw;
}

BoardFields Board::getField(unsigned int row, unsigned int col) try
{
    return board_.at(row).at(col);
}
catch(std::out_of_range const& ex)
{
    std::cerr << "Dimensions ouf of range: " << ex.what() << std::endl;
    throw;
}

BLine Board::getRow(unsigned int row) try
{
    return board_.at(row);
}
catch(std::out_of_range const& ex)
{
    std::cerr << "Invalid dimensions: " << ex.what() << std::endl;
    throw;
}

BLine Board::getCol(unsigned int col) try
{
    BLine result(sizeRows_);

    for(int i = 0; i < sizeRows_; i++)
    {
        result[i] = board_.at(i).at(col);
    }
    return result;
}
catch(std::out_of_range const& ex)
{
    std::cerr << "Invalid dimensions: " << ex.what() << std::endl;
    throw;
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

Lines Board::getCluesCols() const
{
    return cluesCols_;
}

Lines Board::getCluesRows() const
{
    return cluesRows_;
}

bool Board::isSolved()
{
    return (not checkIfAnyFieldIsUnknown()) &&
                verifyRows() &&
                verifyCols();
}

void Board::display() const
{
    std::cout << DisplayBoard::display(*this);
}

bool Board::checkIfAnyFieldIsUnknown()
{
    return std::all_of(board_.begin(), board_.end(), [](const auto line)
    {
        return std::any_of(line.cbegin(),  line.cend(), [](const auto elem)
        {
            return elem == BoardFields::UNKNOWN;
        });
    });
}

bool Board::verifyRows()
{
    for(int row = 0; row < getSizeRows(); row++)
        if(not verifyLine(getRow(row), getCluesRows()[row]))
            return false;

    return true;
}

bool Board::verifyCols()
{
    for(int col = 0; col < getSizeCols(); col++)
        if(not verifyLine(getCol(col), getCluesCols()[col]))
            return false;

    return true;
}

bool Board::verifyLine(BLine line, Line clues)
{
    return clues == countContinousBlackFields(line);
}

Line Board::countContinousBlackFields(BLine line)
{
    Line result;
    bool continous = false;
    unsigned int counter = 0;

    for(auto elem : line)
    {
        if(elem == BoardFields::BLACK)
        {
            counter++;
            continous = true;
        }
        else if(continous == true)
        {
            result.emplace_back(counter);
            counter = 0;
            continous = false;
        }
    }

    if(continous == true)
        result.emplace_back(counter);

    return result;
}
