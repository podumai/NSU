// ----------------------LAB8_0----------------------
// |              Function prototypes               |
// --------------------------------------------------

#pragma once

#include <stdbool.h>
#include <stdint.h>

#define MIN_VERTICES 0
#define MIN_EDGES 0
#define MAX_VERTICES 5000
#define MAX_EDGES(type, n) n * (n - 1) / 2

typedef struct {
    int8_t status;
    int16_t vertex1;
    int16_t vertex2;
    int32_t weight;
} EDGE;

typedef struct {
    int16_t position;
    int16_t vertex1;
    int16_t vertex2;
} SPAN_TREE;

#ifndef LAB8_0_H_
#define LAB8_0_H_

void errorMessage(int8_t);

bool input(int16_t*, int16_t*);

EDGE* createArray(int16_t*);

bool isValid(int16_t*, int16_t*, int32_t*, int16_t*);

void swapVertex(int16_t*, int16_t*);

bool fillArray(EDGE*, int16_t*, int16_t*);

void swapArr(EDGE*, EDGE*);

void sortArray(EDGE*, int16_t*);

void createTree(SPAN_TREE*, EDGE*, int16_t*, int16_t*);

bool inTree(EDGE*, SPAN_TREE*, int16_t*);

bool isCycle(EDGE*, SPAN_TREE*, int16_t*);

void swapTree(SPAN_TREE*, SPAN_TREE*);

void sortTree(SPAN_TREE*, int16_t*);

bool checkTree(SPAN_TREE*, EDGE*, int16_t*, int16_t*);

void output(SPAN_TREE*, int16_t*);

void kruskalAlgorithm(EDGE*, int16_t*, int16_t*);

#endif