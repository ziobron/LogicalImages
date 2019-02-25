#include "DisplayBoard.hpp"

namespace
{
    std::string drawPadding(const int width);
    std::string drawEndLine(const int width);
    std::string drawEmptyLine(const int width);
    std::string drawColumns(const int maxElementsInRows, const int colNumber, const int heightCol);
    std::string drawRow(const int maxElementsInRows);
}


namespace DisplayBoard
{
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
        return ss;
    }

    const void printBoard(const Board& b)
    {
        std::cout << b;
    }

    void foo(Board& b){
        std::cout << b.rowNumber_;
    }
}


namespace
{
    const char HORIZONTAL = '-';
    const char VERTICAL = '|';
    const char INTERSECTION = '+';
    const char PADDING = ' ';

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
        columns += " " + drawPadding(maxElementsInRows);
        columns += drawEndLine(colNumber) + "\n";
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

}

std::ostream& operator<<(std::ostream& os,const Board& b)
{
    int width = b.getColsNumber();
    int height = b.getRowsNumber();
    int widthRows = b.getLabelRowsWidth();
    int heightCol = b.getLabelColsHeight();

    std::stringstream tmp = DisplayBoard::drawBoard(width, height, widthRows, heightCol);
    return os << tmp.str() << "\n";
}

