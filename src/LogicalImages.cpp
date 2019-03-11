#include "LogicalImages.hpp"
#include <memory>
#include <iostream>
#include "JSONFileReader.hpp"


LogicalImages::LogicalImages(std::shared_ptr<Board> b,
                             std::shared_ptr<Algorithm> a)
    : board_(b),
      algorithm_(a)
{}

LogicalImages::~LogicalImages() {}

void LogicalImages::solve()
{
    if (algorithm_->solve(board_))
    {
        std::cout << "Puzzle solved!" << std::endl;
        board_->display();
    } else {
        std::cout << "Solution wasn't found :(" << std::endl;
    }
}
