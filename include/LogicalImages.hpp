#pragma once
#include "Board.hpp"
#include "Algorithm.hpp"

class LogicalImages
{
    std::shared_ptr<Board> board_;
    std::shared_ptr<Algorithm> algorithm_;
public:
    LogicalImages(std::shared_ptr<Board> b,
                  std::shared_ptr<Algorithm> a);
    LogicalImages(std::string path,
                  std::shared_ptr<Algorithm> a);
    ~LogicalImages();

    void solve();
};
