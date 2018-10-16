#include "JSONFileReader.hpp"
#include <fstream>

JSONFileReader::JSONFileReader(std::string path)
    : path_(path)
{
    std::ifstream inputFile(path);
    inputFile >> j_;
}

int JSONFileReader::readRowsNumber()
{
    return j_["rowNumber"];
}

int JSONFileReader::readColsNumber()
{
    return j_["colNumber"];
}

Lines JSONFileReader::readRows()
{
    return j_["rows"];
}

Lines JSONFileReader::readCols()
{
    return j_["cols"];
}
