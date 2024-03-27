// ------------------------Dijkstra Algorithm------------------------
// |                  Finding the shortest path                     |
// |         from the top of the graph to all the others            |
// ------------------------------------------------------------------
#include "lab9.h"

int32_t main() {
    int32_t **matrix = NULL;
    int16_t amountOfVertices;
    int16_t vertexBegin, vertexEnd;
    int16_t amountOfEdges;

    scanf("%hd", &amountOfVertices);
    scanf("%hd%hd", &vertexBegin, &vertexEnd);
    scanf("%hd", &amountOfEdges);

    if (checkInput(amountOfVertices, amountOfEdges, vertexBegin, vertexEnd)) {
        matrix = initMatrix(amountOfVertices);
        
        if (inputMatrix(matrix, amountOfEdges, amountOfVertices) && matrix) {
            dijkstra(matrix, amountOfVertices, amountOfEdges, vertexBegin, vertexEnd);
            freeMatrix(matrix, amountOfVertices);
        }
    }

    return 0;
}