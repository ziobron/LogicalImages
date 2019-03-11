#include "Algorithm.hpp"

Algorithm::Algorithm() {}
Algorithm::~Algorithm() {}

AlgorithmA::AlgorithmA() {}
bool AlgorithmA::solve(std::shared_ptr<Board> b)
{
    b->display();
    return true;
}
