// --------------------------------------------------
// |               Topological Sort                 |
// |  Ordering the vertices of an acyclic directed  |
// |      graph according to partial order          |
// --------------------------------------------------
#include <stdlib.h>
#include "lab7.h"

int32_t main() {

    Link *matrix = NULL;
    Link *preVisited = NULL;
    int16_t vertices;
    int16_t edges;

    if (input(&vertices, &edges)) {

        matrix = createMatrix(vertices);

        if (fillMatrix(matrix, vertices, edges)) {

            preVisited = makeVisited(vertices);

            if (preVisited) {

                if (!isCycled(matrix, vertices, preVisited) &&
                    isConnected(matrix, vertices))
                    topologicalSort(matrix, vertices);

            }
            else
                errorMessage(ALLOC_ERR);

            free(preVisited);

        }

        free(matrix);

    }

    return 0;

}
