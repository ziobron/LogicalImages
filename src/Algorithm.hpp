#pragma once
#include "Board.hpp"

class Algorithm
{
// protected:
//     Board board_;
public:
    Algorithm();
    virtual ~Algorithm();

    virtual bool solve(std::shared_ptr<Board> b) = 0;
};

class AlgorithmA : public Algorithm
{
public:
    AlgorithmA();

    bool solve(std::shared_ptr<Board> b);
};
