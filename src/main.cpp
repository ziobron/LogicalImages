#include <iostream>
#include "LogicalImages.hpp"
#include "DisplayBoard.hpp"


int main()
{
    std::cout << "LogicalImages!\n\n";

    //added temporarily
    Board board(4,
                4,
                {{1},{3},{5}},
                {{3},{5},{6},{2,7}});

    std::cout << board;
    board.newDraw();

    return 0;
}
