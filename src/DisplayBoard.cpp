#include "DisplayBoard.hpp"

//margin from left edge of terminal
static const std::string margin = "   ";

namespace
{
    std::string drawPadding(const int width);
    std::string drawEndLine(const int width);
    std::string drawEmptyLine(const int width, const char PADDING = ' ');
    std::string drawColumns(const int maxElementsInRows, const int colNumber, const int heightCol);
    std::string drawRow(const int maxElementsInRows);
    std::stringstream drawEmptyBoard();
}


namespace DisplayBoard
{
    std::stringstream printBoard(const Board& b)
    {
        int width = b.getColsNumber();
        int height = b.getRowsNumber();
        int widthRows = b.getLabelRowsWidth();
        int heightCol = b.getLabelColsHeight();

        if(width == 0 or height == 0)
            return drawEmptyBoard();

        return DisplayBoard::drawBoard(width, height, widthRows, heightCol);
    }

    std::stringstream drawBoard(const unsigned int width,
                                const unsigned int height,
                                const unsigned int widthRows,
                                const unsigned int heightCol,
                                const char padding /*= ' '*/)
    {
        std::stringstream ss;
        std::string s = drawEndLine(widthRows);
        s = margin + s;
        s.pop_back();

        ss << drawColumns(widthRows, width, heightCol);
        ss << s << drawEndLine(width) << "\n";
        for (int i = height;i > 0 ; --i)
        {
            ss << drawRow(widthRows);
            ss << drawEmptyLine(width, padding) << "\n";
        }
        ss << s << drawEndLine(width);
        return ss;
    }
}


namespace
{
    const char HORIZONTAL = '-';
    const char VERTICAL = '|';
    const char INTERSECTION = '+';
    const char PADDING = ' ';

    std::stringstream drawEmptyBoard()
    {
        const char backGround = '?';
        const int width = 3;
        const int height = 3;
        const int widthRows = 0;
        const int heightCol = 0;

        return DisplayBoard::drawBoard(width, height, widthRows, heightCol, backGround);
    }


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

    std::string drawEmptyLine(const int width, const char PADDING /*= ' '*/)
    {
        std::string result {VERTICAL};
        for (auto it = 0; it < (width * 2); it++)
            result += PADDING;
        result += VERTICAL;
        return result;
    }

    std::string drawColumns(const int maxElementsInRows, const int colNumber, const int heightCol)
    {
        std::string columns {margin};
        columns += " " + drawPadding(maxElementsInRows);
        columns += drawEndLine(colNumber) + "\n";
        for(int i = heightCol; i > 0; --i)
        {
            columns += " " + drawPadding(maxElementsInRows);
            columns += margin + drawEmptyLine(colNumber);
            columns += "\n";
        }
        return columns;
    }

    std::string drawRow(const int maxElementsInRows)
    {
        std::string rows {margin};
        rows += VERTICAL;
        rows += drawPadding(maxElementsInRows);
        return rows;
    }

}

std::ostream& operator<<(std::ostream& os,const Board& b)
{
    auto tmp = DisplayBoard::printBoard(b);
    return os << tmp.str() << "\n\n";
}

