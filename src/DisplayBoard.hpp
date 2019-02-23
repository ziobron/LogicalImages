#pragma once
#include <sstream>
#include <iostream>

namespace DisplayBoard
{
    std::stringstream drawBoard(const int width,
                            const int height,
                            const int widthRows,
                            const int heightCol);

    void printBoard(const int width,
                    const int height,
                    const int widthRows,
                    const int heightCol);

}



