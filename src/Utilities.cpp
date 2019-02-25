#include <fstream>
#include <string>
#include <iostream>
#include <exception>

std::ifstream openFileToRead(const std::string & filename)
{
    try
    {
        std::ifstream data(filename);
        data.exceptions(std::ifstream::failbit);
        return data;
    }
    catch (std::exception)
    {
        std::cout << "Input operation failed (formatting or extraction error)." << std::endl;
        throw;
    }
}

std::ofstream openFileToWrite(const std::string & filename)
{
    try
    {
        std::ofstream data(filename);
        data.exceptions(std::ofstream::failbit);
        return data;
    }
    catch (std::exception)
    {
        std::cout << "Input operation failed (formatting or extraction error)." << std::endl;
        throw;
    }
}
