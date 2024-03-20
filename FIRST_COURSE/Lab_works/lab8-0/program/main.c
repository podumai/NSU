// ----------------------Kruskal's Algorithm----------------------
// |  Algorithm for constructing a minimum spanning tree for a   |
// |            weighted connected undirected graph              |
// ---------------------------------------------------------------

#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "lab8_0.h"

int32_t main() {
    EDGE *array = NULL;
    int16_t vertices;
    int16_t edges;

    if (input(&vertices, &edges)) {

        array = createArray(&edges);

        if (array) {
            if (fillArray(array, &edges, &vertices)) {
                sortArray(array, &edges);
                kruskalAlgorithm(array, &edges, &vertices);
            }
        }
    }

    free(array);

    return 0;
}