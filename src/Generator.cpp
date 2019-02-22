#include "Generator.hpp"

Lines getAllVectorPermutation_(int vSize)
{
    std::vector<int> row(vSize);
    Lines result;

    for(;;)
    {
        result.emplace_back(row);

        for (int i = row.size() - 1; ; --i)
        {
            if (i < 0) return result;

            if (++row[i] == 2) row[i] = 0;
            else break;
        }
    }
}

BLines ConvertIntToFieldEnum(Lines board)
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
