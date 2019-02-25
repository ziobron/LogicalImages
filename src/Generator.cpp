#include "Generator.hpp"

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

BLines ConvertIntToFieldEnum(const Lines& board)
{
    BLines result;

    for(auto line : board)
    {
        BLine row(line.size());
        std::transform(line.begin(), line.end(), row.begin(),
            [](int elem){return (elem ? FieldsEnum::BLACK : FieldsEnum::WHITE);});

        result.emplace_back(row);
    }
    return result;
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
