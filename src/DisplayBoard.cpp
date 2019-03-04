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
                            const unsigned int heightCol,
                            const std::vector<std::string> stringClues);
    std::vector<std::string> getStringFromColumns(const unsigned int sizeCols,
                                                  const Lines cluesCols);
    std::string drawRowOfColumns(const unsigned pos,
                           std::vector<std::string> clues);


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
    const Lines cluesCols = b.getCluesCols();
    std::vector<std::string> stringClues = getStringFromColumns(heightCol, cluesCols);
    std::stringstream output;

    output << drawColumns(widthRows, width, heightCol, stringClues);
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
                        const unsigned int heightCol,
                        const std::vector<std::string> stringClues)
{
    std::string columns;

    columns += PADDING + drawPadding(maxElementsInRows);
    columns += drawEndLine(colNumber) + "\n";

    for (unsigned i = heightCol; i > 0; --i)
    {
        columns += PADDING + drawPadding(maxElementsInRows);
        if(stringClues.size() == 0)
            columns += drawEmptyLine(colNumber);
        else
        {
            columns += VERTICAL;
            columns += drawRowOfColumns(i,stringClues);
            columns += VERTICAL;
         }
        columns += "\n";
    }
    return columns;
}

std::vector<std::string> getStringFromColumns(const unsigned int sizeCols,
                                              const Lines cluesCols)
{
    std::vector<std::string> stringLines;
    std::for_each(cluesCols.begin(), cluesCols.end(),
                  [&](const auto line)
    {
        std::string strline = {};
        std::for_each(line.begin(), line.end(),
                     [&](const auto i)
        {
            strline += std::to_string(i);
        });
        if(strline.size() < sizeCols)
            while (strline.size() != sizeCols) {
                strline.push_back(' ');
            }
        stringLines.emplace_back(strline);
    });
    return stringLines;
}

std::string drawRowOfColumns(const unsigned pos,
                       std::vector<std::string> clues)
{
    std::string columns {};
    std::string s = " ";
    for(auto line : clues)
    {
        columns += s + line.at(pos-1);
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
