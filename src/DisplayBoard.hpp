#pragma once
#include <sstream>
#include <iostream>
#include "Board.hpp"


std::ostream& operator<<(std::ostream& os,const Board& b);

namespace DisplayBoard
{
    std::stringstream drawBoard(const int width,
                                const int height,
                                const int widthRows,
                                const int heightCol);

    const void printBoard(const Board& b);

}


