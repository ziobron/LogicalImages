#include "DisplayBoard.hpp"

std::string drawPadding(const int width)
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

std::string drawEmptyLine(const int width)
{
    std::string result {VERTICAL};
    for (auto it = 0; it < (width * 2); it++)
        result += PADDING;
    result += VERTICAL;
    return result;
}

std::string drawColumns(const int maxElementsInRows, const int colNumber, const int heightCol)
{
    std::string columns;
    for(int i = heightCol; i > 0; --i)
    {
        columns += " " + drawPadding(maxElementsInRows);
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

std::stringstream drawBoard(const int width,
                            const int height,
                            const int widthRows,
                            const int heightCol)
{
    std::stringstream ss;
    std::string s = drawEndLine(widthRows);
    s.pop_back();

    ss << drawColumns(widthRows, width, heightCol);
    ss << s << drawEndLine(width) << "\n";
    for (int i = height;i > 0 ; --i)
    {
        ss << drawRow(widthRows);
        ss << drawEmptyLine(width) << "\n";
    }
    ss << s << drawEndLine(width);
    return  ss;
}
