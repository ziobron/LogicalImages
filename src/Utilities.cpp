#include "Utilities.hpp"
#include <iostream>
#include <exception>
#include <algorithm>

std::ifstream openFileToRead(const std::string& filename)
{
    try
    {
        std::ifstream data(filename);
        data.exceptions(std::ifstream::failbit);
        return data;
    }
    catch (const std::exception& e)
    {
        std::cout << "Failed to open file: " << filename << ". " << e.what() << std::endl;
        throw;
    }
}

std::ofstream openFileToWrite(const std::string& filename)
{
    try
    {
        std::ofstream data(filename);
        data.exceptions(std::ofstream::failbit);
        return data;
    }
    catch (const std::exception& e)
    {
        std::cout << "Failed to open file: " << filename << ". " << e.what() << std::endl;
        throw;
    }
}

BLines ConvertIntToFieldEnum(const Lines& board)
{
    BLines result;

    for(auto line : board)
    {
        BLine row(line.size());
        std::transform(line.begin(), line.end(), row.begin(),
            [](int elem){return (elem ? BoardFields::BLACK : BoardFields::WHITE);});

        result.emplace_back(row);
    }
    return result;
}
