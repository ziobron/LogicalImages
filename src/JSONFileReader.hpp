#pragma once
#include "Board.hpp"

class JSONFileReader
{
    std::string path_;
    json j_;
public:
    JSONFileReader(std::string path);
    int readRowsNumber();
    int readColsNumber();
    Lines readRows();
    Lines readCols();
};
