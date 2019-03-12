#include "Algorithm.hpp"

class AlgorithmStubA : public Algorithm
{
public:
    AlgorithmStubA() {}

    bool solve(std::shared_ptr<Board> b)
    {
        return true;
    }
};

class AlgorithmStubB : public Algorithm
{
public:
    AlgorithmStubB() {}

    bool solve(std::shared_ptr<Board> b)
    {
        return false;
    }
};
