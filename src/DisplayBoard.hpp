#pragma once
#include <sstream>
#include <iostream>
#include "Board.hpp"

std::ostream& operator<<(std::ostream& os,const Board& b);

namespace DisplayBoard
{
    std::string display(const Board& b);
}

