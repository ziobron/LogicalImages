#include "JSONFileReader.hpp"
#include <fstream>

JSONFileReader::JSONFileReader(std::string path)
{
    std::ifstream inputFile(path);
    inputFile >> j_;
}

int JSONFileReader::readRowSize()
{
    if (j_["sizeRows"] < 3)
        throw InvalidDimensions();
    return j_["sizeRows"];
}

int JSONFileReader::readColSize()
{
    if (j_["sizeCols"] < 3)
        throw InvalidDimensions();
    return j_["sizeCols"];
}

Lines JSONFileReader::readCluesRows()
{
    if (j_["sizeRows"] != j_["cluesRows"].size())
        throw InvalidDimensions();
    return j_["cluesRows"];
}

Lines JSONFileReader::readCluesCols()
{
    if (j_["sizeCols"] != j_["cluesCols"].size())
        throw InvalidDimensions();
    return j_["cluesCols"];
}
