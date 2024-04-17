// *************************************************
// |      Prototypes of the main functions of      |
// |                 the program                   |
// *************************************************
#pragma once

#define MAX_EDGES(type, vertices) (vertices * (vertices - 1))

enum CHOICE {
    VRTX = 1,
    EDGS = 2,
    EDG = 3,
    SHOW = 4
};

enum LIMITS {
    MIN_VRTX = 1,
    MAX_VRTX = 2047,
    MIN_EDGES = 0
};

#include <inttypes.h>

typedef struct
{
    uint16_t *storage;
    int16_t capacity;
    int16_t size;
} Stack;

typedef struct
{
    uint32_t vertices : 11;
    uint32_t edges : 21;
    int8_t *matrix;
} Graph;

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

Graph *makeGraph(int16_t, int32_t);

Stack *makeStack(uint16_t);

int8_t *makeVisited(Graph*);

uint16_t *makeSet(Graph*);

int8_t input(Graph**);

int8_t getGraph(Graph**);

void getChoice(int8_t*);

int8_t checkVertex(int16_t, int16_t, uint16_t);

int8_t isConnected(Graph*);

void connectGraph(Graph*, int8_t*, uint16_t*, uint16_t, uint16_t);

void dfs(Graph*, int8_t*, Stack*, uint16_t);

uint16_t findScc(Graph*, int8_t*, uint16_t, uint16_t);

void refreshVisited(int8_t*, Graph*);

int8_t checkChoice(int8_t);

int8_t getSort(Graph*, Stack**);

void kosarajuAlgorithm(Graph*, Stack*);

void freeGraph(Graph**);

void freeStack(Stack**);

#endif
