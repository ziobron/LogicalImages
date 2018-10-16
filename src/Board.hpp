#pragma once
#include "json.hpp"
#include <vector>
#include <exception>

using Line = std::vector<int>;
using Lines = std::vector<Line>;
using json = nlohmann::json;

class Board
{
    int rowNumber_;
    int colNumber_;
    Lines rows_;
    Lines cols_;
    Lines board_;

public:
    Board(int rowNumber,
          int colNumber,
          const Lines& rows,
          const Lines& cols) noexcept;
    Board(std::string path);
    ~Board();

    int getRowsNumber() const;
    int getColsNumber() const;
};

class InvalidDimensions : public std::exception
{
    std::string reason;
public:
    InvalidDimensions(const char* why)
        : reason(why)
    {}

    virtual const char* what() const throw()
    {
        return reason.c_str();
    }
};
