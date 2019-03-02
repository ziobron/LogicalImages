#include "DisplayBoard.hpp"

namespace
{
    const char HORIZONTAL = '-';
    const char VERTICAL = '|';
    const char INTERSECTION = '+';
    const char PADDING = ' ';


    std::string drawPadding(const unsigned int width,
                            const char sign = PADDING);

    std::string drawEndLine(const unsigned int widthRows, const unsigned int width = 0);
    std::string drawEmptyLine(const unsigned int width,
                              const char sign = PADDING);

    std::string drawColumns(const unsigned int maxElementsInRows,
                            const unsigned int colNumber,
                            const unsigned int heightCol);

    std::string drawRow(const unsigned int maxElementsInRows);
}

namespace DisplayBoard
{
std::string display(const Board& b)
{
    auto width = b.getRowsNumber();
    auto height = b.getColsNumber();
    auto widthRows = b.getLongestRowLenght();
    auto heightCol = b.getLongestColLenght();
    std::stringstream output;

    output << drawColumns(widthRows, width, heightCol);
    output << drawEndLine(widthRows, width) << "\n";

    for (int i = 0; i < height; i++)
    {
        output << drawRow(widthRows);
        output << drawEmptyLine(width, '?') << "\n";
    }
    output << drawEndLine(widthRows, width);

    return output.str() + "\n";
}
}

namespace
{
std::string drawPadding(const unsigned int width,
                        const char sign /*= PADDING*/)
{
    std::string result;

    for (auto it = 0; it < (width * 2); it++)
        result += sign;

    return result;
}

std::string drawEndLine(const unsigned int widthRows, const unsigned int width)
{
    std::string result {INTERSECTION};

     for (auto it = 0; it < (widthRows *2); it++)
         result += HORIZONTAL;
    result += INTERSECTION;

    if(width > 0)
    {
        for (auto it = 0; it < (width *2); it++)
            result += HORIZONTAL;
        result += INTERSECTION;
    }

    return result;
}

std::string drawEmptyLine(const unsigned int width,
                          const char sign /*= PADDING*/)
{
    std::string result {VERTICAL};

    for (auto it = 0; it < (width * 2); it++)
        result += sign;
    result += VERTICAL;

    return result;
}

std::string drawColumns(const unsigned int maxElementsInRows,
                        const unsigned int colNumber,
                        const unsigned int heightCol)
{
    std::string columns;

    columns += PADDING + drawPadding(maxElementsInRows);
    columns += drawEndLine(colNumber) + "\n";

    for (int i = heightCol; i > 0; --i)
    {
        columns += PADDING + drawPadding(maxElementsInRows);
        columns += drawEmptyLine(colNumber);
        columns += "\n";
    }

    return columns;
}

std::string drawRow(const unsigned int maxElementsInRows)
{
    std::string rows;

    rows += VERTICAL;
    rows += drawPadding(maxElementsInRows);

    return rows;
}
}

std::ostream& operator<<(std::ostream& os, const Board& b)
{
    return os << DisplayBoard::display(b);
}
