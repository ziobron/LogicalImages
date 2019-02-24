#pragma once
#include "Board.hpp"

// Fuction to generate next permutation for given vector (Line)
// input:
//     Line row - reference to vector to permute
// output:
//     bool - true when permutation with hihgest value has been reached, false otherwise
bool nextPermutation(Line &row);

// Fuction converts given board of values from range {0, 1} to corensponding valies of FieldsEnum
// input:
//     Lines board - board of int values to be converted
// output:
//     Blines result - board of FieldsEnum values
BLines ConvertIntToFieldEnum(const Lines & board);

// Function to generate all permutation for board of given size.
// input:
//     uint rowSize - number of rows in board
//     uint colSize - number of columns in board
// output:
//     vector<Lines> - vector of all permutation that board can have stored in Lines format
std::vector<Lines> GenerateAllBoardPermutations(unsigned int rowSize, unsigned int colSize);
