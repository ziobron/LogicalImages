#include "Generator.hpp"
#include "Utilities.hpp"

bool nextPermutation(Line& row)
{
    for (int i = row.size() - 1; ; --i)
    {
        if (i < 0)
            return true;

        if (++row[i] == 2)
            row[i] = 0;
        else
            break;
    }
    return false;
}

std::vector<Lines> GenerateAllBoardPermutations(unsigned int rowSize, unsigned int colSize)
{
    std::vector<Lines> result;
    Lines board(rowSize, Line(colSize));
    int i = 0;

    while(true) {
        result.emplace_back(board);

        while (nextPermutation(board[i]))
            if (++i >= rowSize)
                break;

        if (i >= rowSize)
            break;
        else
            i = 0;
    }
    return result;
}
