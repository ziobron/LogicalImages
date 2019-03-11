#pragma once
#include "Board.hpp"

class Algorithm
{
public:
    Algorithm();
    virtual ~Algorithm();

    virtual bool solve(std::shared_ptr<Board> b) = 0;
};
