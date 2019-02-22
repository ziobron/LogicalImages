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
