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

std::stringstream drawBoard(const int width, const int height)
{
    std::stringstream s;
    s << drawEndLine(width) << std::endl;
    for (int i = height;i > 0 ; --i){
        s << drawEmptyLine(width) << std::endl;
    }
    s << drawEndLine(width);
    return  s;
}
