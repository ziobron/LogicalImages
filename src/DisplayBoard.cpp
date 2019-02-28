#include "DisplayBoard.hpp"

namespace
{
    const char HORIZONTAL = '-';
    const char VERTICAL = '|';
    const char INTERSECTION = '+';
    const char PADDING = ' ';


    std::string drawPadding(const unsigned int width,
                            const char sign = PADDING);

    std::string drawEndLine(const unsigned int width);
    std::string drawEmptyLine(const unsigned int width,
                              const char sign = PADDING);

    std::string drawColumns(const unsigned int maxElementsInRows,
                            const unsigned int colNumber,
                            const unsigned int heightCol);

    std::string drawRow(const unsigned int maxElementsInRows);
    std::stringstream drawBoard(const unsigned int width,
                                const unsigned int height,
                                const unsigned int widthRows,
                                const unsigned int heightCol);
}

namespace DisplayBoard
{
    std::string displayInterface(const Board& b){
        auto width = b.getRowsNumber();
        auto height = b.getColsNumber();
        auto widthRows = b.findLongestVectorInRows();
        auto heightCol = b.findLongestVectorInCols();

        auto tmp = drawBoard(width, height, widthRows, heightCol);
        return tmp.str();
    }
}

namespace
{
    std::stringstream drawBoard(const unsigned int width,
                                const unsigned int height,
                                const unsigned int widthRows,
                                const unsigned int heightCol)
    {
        std::stringstream ss;
        std::string s = drawEndLine(widthRows);
        s.pop_back();

        ss << drawColumns(widthRows, width, heightCol);
        ss << s << drawEndLine(width) << "\n";
        for (int i = height; i > 0; --i)
        {
            ss << drawRow(widthRows);
            ss << drawEmptyLine(width, '?') << "\n";
        }
        ss << s << drawEndLine(width);
        return ss;
    }

    std::string drawPadding(const unsigned int width,
                            const char sign /*= PADDING*/)
    {
        std::string result;
        for (auto it = 0; it < (width * 2); it++)
            result += PADDING;
        return result;
    }

    std::string drawEndLine(const unsigned int width)
    {
        std::string result {INTERSECTION};
        for (auto it = 0; it < (width *2); it++)
            result += HORIZONTAL;
        result += INTERSECTION;
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
        for(int i = heightCol; i > 0; --i)
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
