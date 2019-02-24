#pragma once
#include <sstream>
#include <iostream>

namespace DisplayBoard
{
    std::ostringstream drawBoard(const int width,
                                 const int height,
                                 const int widthRows,
                                 const int heightCol);
}



