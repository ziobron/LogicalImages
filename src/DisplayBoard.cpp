#include "DisplayBoard.hpp"
#include <algorithm>

namespace
{
    const char HORIZONTAL = '-';
    const char VERTICAL = '|';
    const char INTERSECTION = '+';
    const char PADDING = ' ';

    std::string drawPadding(const unsigned int width,
                            const char sign = PADDING);

    std::string drawEndLine(const unsigned int widthRows,
                            const unsigned int width = 0);

    std::string drawBoardLine(const unsigned int width,
                              BLine boardLine = {});

    std::string drawColumns(const unsigned int maxElementsInRows,
                            const unsigned int sizeCols,
                            const unsigned int heightCol,
                            const std::vector<std::string> & stringClues);

    std::vector<std::string> getFormattedColumns(const unsigned int sizeCols,
                                                  const Lines & cluesCols);

    std::string drawRowOfColumns(const unsigned pos,
                           const std::vector<std::string> & clues);

    std::string drawRow(const unsigned int maxElementsInRows, const Line & row);
}

namespace DisplayBoard
{
std::string display(const Board& b)
{
    auto width = b.getSizeRows();
    auto height = b.getSizeCols();
    auto widthRows = b.getLongestCluesLenghtInRows();
    auto heightCol = b.getLongestCluesLenghtInCols();
    const Lines cluesRows = b.getCluesRows();
    std::stringstream output;

    output << drawColumns(widthRows, width, heightCol, getFormattedColumns(heightCol, b.getCluesCols()));
    output << drawEndLine(widthRows, width) << "\n";

    for (int i = 0; i < height; i++)
    {
        if(cluesRows.size() != height)
            output << drawRow(widthRows, {});
        else
            output << drawRow(widthRows, cluesRows.at(i));
        output << drawBoardLine(width, b.getBoardLines().at(i)) << "\n";
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

std::string drawBoardLine(const unsigned int width, BLine boardLine)
{
    std::string result {VERTICAL};
    for (const auto & it : boardLine)
    {
        result += static_cast<char>(it);
        result += static_cast<char>(it);
    }
    result += VERTICAL;
    return result;
}

std::string drawColumns(const unsigned int maxElementsInRows,
                        const unsigned int sizeCols,
                        const unsigned int heightCol,
                        const std::vector<std::string> & stringClues)
{
    std::string columns;

    columns += PADDING + drawPadding(maxElementsInRows);
    columns += drawEndLine(sizeCols) + "\n";

    for (int i = heightCol; i > 0; --i)
    {
        columns += PADDING + drawPadding(maxElementsInRows);
        columns += VERTICAL;
        columns += drawRowOfColumns(i, stringClues);
        columns += VERTICAL;
        columns += "\n";
    }
    return columns;
}

std::vector<std::string> getFormattedColumns(const unsigned int sizeCols,
                                              const Lines & cluesCols)
{
    std::vector<std::string> stringLines;
    if(not cluesCols.empty())
        for(const auto & clueCol : cluesCols)
        {
            std::string strline {};
            std::transform(clueCol.begin(), clueCol.end(), std::back_inserter(strline),
                         [&](const auto i)
            {
                return std::to_string(i).at(0);
            });
            if(strline.size() < sizeCols)
                while (strline.size() != sizeCols) {
                    strline.push_back(PADDING);
                }
            stringLines.emplace_back(strline);
        }
    return stringLines;
}

std::string drawRowOfColumns(const unsigned pos,
                       const std::vector<std::string> & clues)
{
    std::string columns;
    if(not clues.empty())
        for(const auto & line : clues)
        {
            columns += PADDING;
            columns += line.at(pos - 1);
        }
    return columns;
}

std::string drawRow(const unsigned int maxElementsInRows, const Line & row)
{
    std::string rows;

    rows += VERTICAL;
    if(row.empty())
    {
        rows += drawPadding(maxElementsInRows);
    }
    else
    {
        if(row.size() < maxElementsInRows)
        {
            for(int i = maxElementsInRows - row.size(); i > 0; i--)
            {
                rows.push_back(PADDING);
                rows.push_back(PADDING);
            }
        }
        std::for_each(row.begin(), row.end(),
                      [&](auto i)
        {
            rows += PADDING + std::to_string(i);
        });
    }
    return rows;
}

}
