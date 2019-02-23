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



