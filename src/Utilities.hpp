#include <fstream>
#include <string>
#include <vector>
#include "BoardFields.hpp"

using Line = std::vector<int>;
using Lines = std::vector<Line>;
using BLine = std::vector<BoardFields>;
using BLines = std::vector<BLine>;

std::ifstream openFileToRead(const std::string& filename);
std::ofstream openFileToWrite(const std::string& filename);
BLines ConvertIntToBoardFields(const Lines& board);
