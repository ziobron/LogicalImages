#include "Algorithm.hpp"

class AlgorithmStubA : public Algorithm
{
public:
    bool solve(std::shared_ptr<Board> b)
    {
        return true;
    }
};

class AlgorithmStubB : public Algorithm
{
public:
    bool solve(std::shared_ptr<Board> b)
    {
        return false;
    }
};
