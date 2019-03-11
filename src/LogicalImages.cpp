#include "LogicalImages.hpp"
#include <memory>
#include <iostream>
#include "JSONFileReader.hpp"


LogicalImages::LogicalImages(std::shared_ptr<Board> b,
                             std::shared_ptr<Algorithm> a)
    : board_(b),
      algorithm_(a)
{}

LogicalImages::LogicalImages(std::string const path,
                             std::shared_ptr<Algorithm> a)
    : algorithm_(a)
{
    try
    {
        JSONFileReader jfr(path);
        board_ = std::make_shared<Board>(jfr.readRowSize(),
                                         jfr.readColSize(),
                                         jfr.readCluesRows(),
                                         jfr.readCluesCols());
    }
    catch(InvalidDimensions const& ex)
    {
        std::cout << "Invalid JSON file: " << ex.what() << std::endl;
    }
}

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
