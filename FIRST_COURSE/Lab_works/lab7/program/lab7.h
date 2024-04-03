// -----------------------LAB7-----------------------
// |              Function prototypes               |
// |                Description of:                 |
// |                1.   limits                     |
// |                2.   errors                     |
// |                3. structures                   |
// --------------------------------------------------
#pragma once

#define MIN_VERTICES 0
#define MAX_VERTICES 2000
#define MIN_EDGES 0
#define MAX_EDGES(type, n) n * (n - 1) / 2
#define ERR_NUM_PAR 1
#define ERR_NUM_VERT 2
#define ERR_NUM_EDG 3
#define ERR_NUM_LNS 4
#define ERR_VRTX 5
#define ERR_INCHRNT 6
#define ERR_CYCLED 7
#define ALLOC_ERR -1

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint8_t flag : 1;
} Link;

typedef struct {
    uint16_t *storage;
    int16_t capacity;
    int16_t size;
} Stack;

#ifndef LAB7_H_
#define LAB7_H_

void errorMessage(int8_t);

bool input(int16_t*, int16_t*);

void isValidInput(int16_t, int16_t);

Link *createMatrix(int16_t);

bool isValid(int16_t, int16_t, int16_t);

bool fillMatrix(Link*, int16_t, int16_t);

int8_t searchCycle(Link*, int16_t, Link*, int16_t, int16_t);

bool isCycled(Link*, int16_t, Link*);

void connect(Link*, int16_t, uint16_t*, int16_t);

bool isConnected(Link*, int16_t);

void dfs(Link*, Link*, Stack*, int16_t, int16_t);

Link *makeVisited(int16_t);

Stack *makeStack(int16_t);

void topologicalSort(Link*, int16_t);

#endif