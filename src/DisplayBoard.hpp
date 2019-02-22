#pragma once
#include <sstream>

const char HORIZONTAL = '-';
const char VERTICAL = '|';
const char INTERSECTION = '+';
const char PADDING = ' ';

std::string drawPadding(const int width);
std::string drawEndLine(const int width);
std::string drawEmptyLine(const int width);
std::stringstream drawBoard(const int width, const int height);



