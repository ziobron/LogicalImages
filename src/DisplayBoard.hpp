#pragma once
#include <sstream>
#include <iostream>

namespace DisplayBoard
{
    const char HORIZONTAL = '-';
    const char VERTICAL = '|';
    const char INTERSECTION = '+';
    const char PADDING = ' ';
    const char UNKNOWN = '?';

    std::string drawPadding(const int width, const char sign = PADDING);
    std::string drawEndLine(const int width);
    std::string drawEmptyLine(const int width, const char sign = PADDING);
    std::string drawColumns(const int maxElementsInRows, const int colNumber, const int heightCol);
    std::string drawRow(const int maxElementsInRows);
}



