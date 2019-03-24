#pragma once
#include "BoardFields.hpp"
#include "json.hpp"
#include <vector>

using Line = std::vector<int>;
using Lines = std::vector<Line>;
using BLine = std::vector<BoardFields>;
using BLines = std::vector<BLine>;

class Board
{
    const unsigned int sizeRows_;
    const unsigned int sizeCols_;
    Lines cluesRows_;
    Lines cluesCols_;
    BLines board_;

    bool checkIfAnyFieldIsUnknown();
    bool verifyRows();
    bool verifyCols();
    bool verifyLine(BLine line, Line clues);
    Line countContinousBlackFields(BLine line);

public:
    Board(const unsigned int sizeRows,
          const unsigned int sizeCols,
          const Lines& rows,
          const Lines& cols) noexcept;
    ~Board();

    unsigned int getSizeRows() const;
    unsigned int getSizeCols() const;
    const BLines& getBoardLines() const;

    BoardFields getField(unsigned int row, unsigned int col);
    BLine getCol(unsigned int col);
    BLine getRow(unsigned int row);

    void setField(unsigned int row, unsigned int col, BoardFields value);
    void setCol(unsigned int col, BLine values);
    void setRow(unsigned int row, BLine values);

    unsigned int getLongestLineLenght(const Lines& v) const;
    unsigned int getLongestCluesLenghtInRows() const;
    unsigned int getLongestCluesLenghtInCols() const;

    Lines getCluesCols() const;
    Lines getCluesRows() const;

    bool isSolved();
    void display() const;
};
