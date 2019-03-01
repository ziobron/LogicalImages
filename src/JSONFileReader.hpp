#pragma once
#include "Board.hpp"
#include <stdexcept>

using json = nlohmann::json;

class JSONFileReader
{
    json j_;
public:
    explicit JSONFileReader(std::string path);
    int readRowSize();
    int readColSize();
    Lines readRows();
    Lines readCols();
};

struct InvalidDimensions : public std::out_of_range
{
    InvalidDimensions() : std::out_of_range("Number of lines is different than "
                                            "number of cols/rows or number of "
                                            "cols/rows must be at least 3") {}
};
