#pragma once
#include <sstream>
#include <iostream>
#include "Board.hpp"


std::ostream& operator<<(std::ostream& os,const Board& b);

namespace DisplayBoard
{
    std::stringstream drawBoard(const unsigned int width,
                                const unsigned int height,
                                const unsigned int widthRows,
                                const unsigned int heightCol,
                                const char padding = ' ');

    std::stringstream printBoard(const Board& b);

}


