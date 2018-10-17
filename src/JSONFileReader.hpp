#pragma once
#include "Board.hpp"

using json = nlohmann::json;

class JSONFileReader
{
    json j_;
public:
    explicit JSONFileReader(std::string path);
    int readRowsNumber();
    int readColsNumber();
    Lines readRows();
    Lines readCols();
};

class InvalidDimensions : public std::exception
{
    std::string reason;
public:
    explicit InvalidDimensions(const char* why)
        : reason(why)
    {}

    virtual const char* what() const throw()
    {
        return reason.c_str();
    }
};
