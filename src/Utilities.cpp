#include <fstream>
#include <string>
#include <iostream>

bool loadFromFile(const std::string & filename)
{
    std::ifstream data;
    data.open(filename, std::ifstream::in);
    if (data)
    {
        try
        {}
        catch (...)
        {
            std::cout << "Empty board file.";
            return false;
        }
    }
    else
    {
        std::cout << "Board file doesn't exist.";
        return false;
    }
    data.close();
}

bool saveToFile(const std::string & filename)
{
    std::ofstream data;
    data.open(filename, std::ofstream::out);
    if (data)
    {}
    else
    {
        std::cout << "File creation failed, check disk space" << std::endl;
        return false;
    }
    data.close();
}

