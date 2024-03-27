// ------------------------Prim's Algorithm-----------------------
// |  Algorithm for constructing a minimum spanning tree for a   |
// |            weighted connected undirected graph              |
// ---------------------------------------------------------------
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lab8_1.h"

int32_t main() {
    int32_t *weights = NULL;
    int16_t *start = NULL;
    int16_t *end = NULL;
    int16_t vertices;
    int16_t edges;

    if (input(&vertices, &edges)) {

        if (edges) {

            start = (int16_t*)malloc(sizeof(int16_t) * edges);
            end = (int16_t*)malloc(sizeof(int16_t) * edges);
            weights = (int32_t*)malloc(sizeof(int32_t) * edges);

            if (start && end && weights) {

                if (fillArrays(start, end, weights, &edges, &vertices))
                    primAlgorithm(start, end, weights, &edges, &vertices);
            }
            else
                errorMessage(20);
        }
        else if (vertices != 1)
            errorMessage(7);
    }

    free(start);
    free(end);
    free(weights);

    return 0;
}