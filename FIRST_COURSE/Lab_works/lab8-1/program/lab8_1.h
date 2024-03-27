// ----------------------LAB8_1----------------------
// |              Function prototypes               |
// --------------------------------------------------

#pragma once

#include <stdbool.h>
#include <stdint.h>

#define MIN_VERTICES 0
#define MAX_VERTICES 5000
#define MIN_EDGES 0
#define MAX_EDGES(type, n) n * (n - 1) / 2
#define MIN_LEN 0
#define MAX_LEN INT32_MAX
#define INFINITY INT32_MAX

typedef struct {
    int16_t vertex1;
    int16_t vertex2;
} SPAN_TREE;

#ifndef LAB8_1_H_
#define LAB8_1_H_

void errorMessage(int8_t);

bool input(int16_t*, int16_t*);

bool isValid(int16_t*, int16_t*, int32_t*, int16_t*);

bool *makeVisited(int16_t*);

void swap(int16_t*, int16_t*);

void output(SPAN_TREE*, int16_t*);

bool check(bool, bool);

bool fillArrays(int16_t*, int16_t*, int32_t*, int16_t*, int16_t*);

void primAlgorithm(int16_t*, int16_t*, int32_t*, int16_t*, int16_t*);

#endif