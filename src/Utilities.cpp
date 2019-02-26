#include <fstream>
#include <string>
#include <iostream>
#include <exception>

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
        std::cout << "Failed to open file: " << filename <<  ". " << e.what() << std::endl;
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
