#pragma once
#include "Board.hpp"

// getAllVectorPermutation_ is a temporary function to check algorithm if it generates valid
// and correct permutation for given vector when it can only store 2 values {0, 1}
// input:
//    int vSize - size of a vector to find all premutations
// output:
//    Lines result - vector of all posibble combinations of vector of given size
Lines getAllVectorPermutation_(int vSize);

// Fuction converts given board of values from range {0, 1} to corensponding valies of FieldsEnum
// input:
//     Lines board - board of int values to be converted
// output:
//     Blines result - board of FieldsEnum values
BLines ConvertIntToFieldEnum(const Lines & board);
