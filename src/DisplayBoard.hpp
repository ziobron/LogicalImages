#pragma once
#include <sstream>
#include <iostream>
#include "Board.hpp"

std::ostream& operator<<(std::ostream& os,const Board& b);

namespace DisplayBoard
{
    void displayInterface(const Board& b);
}


