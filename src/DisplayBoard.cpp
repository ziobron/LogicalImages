#include "DisplayBoard.hpp"

namespace DisplayBoard
{
    std::string drawPadding(const int width, const char sign)
    {
        std::string result;
        for (auto it = 0; it < (width * 2); it++)
            result += PADDING;
        return result;
    }

    std::string drawEndLine(const int width)
    {
        std::string result {INTERSECTION};
        for (auto it = 0; it < (width *2); it++)
            result += HORIZONTAL;
        result += INTERSECTION;
        return result;
    }

    std::string drawEmptyLine(const int width, const char sign)
    {
        std::string result {VERTICAL};
        for (auto it = 0; it < (width * 2); it++)
            result += sign;
        result += VERTICAL;
        return result;
    }

    std::string drawColumns(const int maxElementsInRows, const int colNumber, const int heightCol)
    {
        std::string columns;
        columns += PADDING + drawPadding(maxElementsInRows);
        columns += drawEndLine(colNumber) + "\n";
        for(int i = heightCol; i > 0; --i)
        {
            columns += PADDING + drawPadding(maxElementsInRows);
            columns += drawEmptyLine(colNumber);
            columns += "\n";
        }
        return columns;
    }

    std::string drawRow(const int maxElementsInRows)
    {
        std::string rows;
        rows += VERTICAL;
        rows += drawPadding(maxElementsInRows);
        return rows;
    }

}

