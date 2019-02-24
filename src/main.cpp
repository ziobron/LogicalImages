#include <iostream>
#include "LogicalImages.hpp"
#include "DisplayBoard.hpp"


int main()
{
    std::cout << "LogicalImages!\n\n";

    //added temporarily
    Board board(6,
                6,
                {{1},{3},{5}},
                {{3},{5},{6},{2,7}});

    Board boardEmpty(0,
                     0,
                    {{1,2}},
                    {{1}});

    std::cout << board;
    std::cout << boardEmpty;


    return 0;
}
