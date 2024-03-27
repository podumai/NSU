// -----------------------LAB9-----------------------
// |              Function prototypes               |
// --------------------------------------------------

#pragma once

#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define INFINITY 5000000000
#define MAX_VERTICES 5000
#define MIN 0

#ifndef LAB9_H_
#define LAB9_H_

bool checkVertices(int16_t);

bool checkVertex(int16_t, int16_t, int16_t);

bool checkEdges(int16_t, int16_t);

bool checkInput(int16_t, int16_t, int16_t, int16_t);

bool checkLength(int32_t);

int32_t **initMatrix(int16_t);

bool inputMatrix(int32_t**, int16_t, int16_t);

void restorePath(int32_t**, int64_t*, int16_t, int16_t, int16_t);

void dijkstra(int32_t**, int16_t, int16_t,  int16_t, int16_t);

void freeMatrix(int32_t**, int16_t);

#endif