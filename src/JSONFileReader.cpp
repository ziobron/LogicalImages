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

Lines JSONFileReader::readRows()
{
    if (j_["sizeRows"] != j_["rows"].size())
        throw InvalidDimensions();
    return j_["rows"];
}

Lines JSONFileReader::readCols()
{
    if (j_["sizeCols"] != j_["cols"].size())
        throw InvalidDimensions();
    return j_["cols"];
}
