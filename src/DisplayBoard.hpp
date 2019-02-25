#pragma once
#include <sstream>
#include <iostream>
#include "Board.hpp"

namespace DisplayBoard
{
    std::string displayInterface(const Board& b);
}

//alias to shortcut name in test files
namespace DB = DisplayBoard;
