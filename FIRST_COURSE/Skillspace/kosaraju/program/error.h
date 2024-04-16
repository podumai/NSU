// *************************************************
// |               Error information               |
// *************************************************
#pragma once

#include <stdint.h>

enum ERRORS {
    NONE_PRMTR = -1,
    BAD_VRTS = -2,
    BAD_EDGS = -3,
    BAD_VRTX = -4,
    BAD_LNS = -5,
    INCHR_GRPH = -6,
    BAD_INPUT = -7,
    GRAPH_ALLOC_ERR = -8,
    STACK_ALLOC_ERR = -9,
    VISITED_ALLOC_ERR = -10,
    SET_ALLOC_ERR = -11,
    SORTED_ALLOC_ERR = -12,
    FILE_ERR = -13,
};

#ifndef ERROR_H_
#define ERROR_H_

void errorMessage(int8_t);

#endif