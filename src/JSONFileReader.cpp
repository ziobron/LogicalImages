#include "JSONFileReader.hpp"
#include <fstream>

JSONFileReader::JSONFileReader(std::string path)
{
    std::ifstream inputFile(path);
    inputFile >> j_;
}

int JSONFileReader::readRowsNumber()
{
    if (j_["rowNumber"] < 3)
        throw InvalidDimensions("Number of rows must be at least 3");
    return j_["rowNumber"];
}

int JSONFileReader::readColsNumber()
{
    if (j_["colNumber"] < 3)
        throw InvalidDimensions("Number of columns must be at least 3");
    return j_["colNumber"];
}

Lines JSONFileReader::readRows()
{
    if (j_["rowNumber"] != j_["rows"].size())
        throw InvalidDimensions("Number of lines is different than number of rows");
    return j_["rows"];
}

Lines JSONFileReader::readCols()
{
    if (j_["colNumber"] != j_["cols"].size())
        throw InvalidDimensions("Number of lines is different than number of cols");
    return j_["cols"];
}
