// ----------------------Functions----------------------
// |           Implementation of functions             |
// -----------------------------------------------------
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "lab9.h"
// -----------------------------------------------------
// |     Checks number of vertices, number of edges    |
// -----------------------------------------------------
bool checkVertices(int16_t amountOfVertices) {
    if (amountOfVertices >= MIN && amountOfVertices <= MAX_VERTICES)
        return true;
    
    printf("bad number of vertices\n");

    return false;
}
// -----------------------------------------------------
// | Checking the staring vertex and the ending vertex |
// -----------------------------------------------------
bool checkVertex(int16_t amountOfVertices, int16_t vertexBegin, int16_t vertexEnd) {
    if (vertexBegin > MIN && vertexBegin <= amountOfVertices)
        if (vertexEnd > MIN && vertexEnd <= amountOfVertices)
            return true;
    
    printf("bad vertex\n");

    return false;
}
// -----------------------------------------------------
// |          Checking the number of edges             |
// -----------------------------------------------------
bool checkEdges(int16_t amountOfVertices, int16_t amountOfEdges) {
    if (amountOfEdges >= MIN && amountOfEdges <= amountOfVertices * (amountOfVertices - 1) / 2)
        return true;
    
    printf("bad number of edges\n");

    return false;
}
// -----------------------------------------------------
// |                Checking parameters                |
// -----------------------------------------------------
bool checkInput(int16_t amountOfVertices, int16_t amountOfEdges, int16_t vertexBegin,
 int16_t vertexEnd) {
    if (checkVertices(amountOfVertices))
        if (checkVertex(amountOfVertices, vertexBegin,  vertexEnd))
            if (checkEdges(amountOfVertices, amountOfEdges))
                return true;
    
    return false;
}
// -----------------------------------------------------
// |      Initializing the connection matrix           |
// -----------------------------------------------------
int32_t **initMatrix(int16_t amountOfVertices) {
    int32_t **matrix = NULL;

    if (amountOfVertices > 0) {
        matrix = (int32_t**)malloc(sizeof(int32_t*) * amountOfVertices);

        if (matrix)
            for (int16_t i = 0; i < amountOfVertices; i++)
                matrix[i] = (int32_t*)calloc(amountOfVertices, sizeof(int32_t));

    }

    return matrix;
}
// -----------------------------------------------------
// |                   Length check                    |
// -----------------------------------------------------
bool checkLength(int32_t length) {
    if (length >= MIN && length <= INT32_MAX)
        return true;
    
    printf("bad length\n");

    return false;
}
// -----------------------------------------------------
// |        Filling the matrix with values             |
// -----------------------------------------------------
bool inputMatrix(int32_t **matrix, int16_t amountOfEdges, int16_t amountOfVertices) {
    int16_t countOfEdges = 0;
    int16_t vertexBegin, vertexEnd;
    int32_t length;

   for (int16_t i = 0; i < amountOfEdges; i++) {
        if (scanf("%hd%hd%d", &vertexBegin, &vertexEnd, &length) == 3) {
            if (checkVertex(amountOfVertices, vertexBegin, vertexEnd) && checkLength(length)) {
                    matrix[vertexBegin - 1][vertexEnd - 1] = length;
                    matrix[vertexEnd - 1][vertexBegin - 1] = length;
            }
            else
                return false;
        }
   }
   
    return true;
}
// -----------------------------------------------------
// |               Restoring the path                  |
// -----------------------------------------------------
void restorePath(int32_t **matrix, int64_t *minPaths, int16_t amountOfVertices,
 int16_t vertexBegin, int16_t vertexEnd) {
    int16_t *path = (int16_t*)malloc(sizeof(int16_t) * amountOfVertices);
    int16_t end = vertexEnd - 1;
    int16_t previuosVertex = 1;
    int64_t weight = minPaths[end];
    int16_t countPaths = 0;

    path[0] = end + 1;

    if (path) {
        while (end != vertexBegin - 1) {
            for (int16_t i = 0; i < amountOfVertices; i++)

                if (matrix[i][end]) {
                    int64_t temp = weight - matrix[i][end];

                    if (temp == minPaths[i]) {
                        weight = temp;
                        end = i;
                        path[previuosVertex] = i + 1;
                        previuosVertex++;
                    }
                }
            
        }

        printf("\n");

        for (int16_t i = 0; i < amountOfVertices; i++)
            if (minPaths[i] >= INT32_MAX && matrix[end][i])
                countPaths++;

        if (previuosVertex == 1 && vertexBegin == vertexEnd)
            printf("%hd", vertexBegin);
        else if (previuosVertex == 1)
            printf("no path");
        else if (countPaths >= 2)
            printf("overflow");
        else
            for (int16_t i = 0; i < previuosVertex; i++)
                printf("%hd ", path[i]);
        
        printf("\n");
    }
}
// -----------------------------------------------------
// |               Dijkstra's algorithm                |
// -----------------------------------------------------
void dijkstra(int32_t **matrix, int16_t amountOfVertices, int16_t amountOfEdges, 
int16_t vertexBegin, int16_t vertexEnd) {
    int64_t *minPaths = NULL;
    bool *summitVertices = NULL;
    int64_t min, minVertex, length;

    if (amountOfEdges > 0) {
        minPaths = (int64_t*)malloc(sizeof(int64_t) * amountOfVertices);
        summitVertices = (bool*)malloc(sizeof(bool) * amountOfVertices);
    }

    if (minPaths && summitVertices) {
        for (int16_t i = 0; i < amountOfVertices; i++) {
            minPaths[i] = INFINITY;
            summitVertices[i] = true;
        }

        minPaths[vertexBegin - 1] = 0;

        do {
            minVertex = INFINITY;
            min = INFINITY;

            for (int16_t i = 0; i < amountOfVertices; i++)
                if (summitVertices[i] && minPaths[i] < min) {
                    min = minPaths[i];
                    minVertex = i;
                }
            
            if (minVertex != INFINITY) {

                for (int16_t i = 0; i < amountOfVertices; i++) {

                    if (matrix[minVertex][i] > 0) {

                        length = min + matrix[minVertex][i];

                        if (length < minPaths[i])
                            minPaths[i] = length;

                    }
                }

                summitVertices[minVertex] = false;
            }

        } while (minVertex < INFINITY);

        for (int16_t i = 0; i < amountOfVertices; i++) {
            if (minPaths[i] == INFINITY)
                printf("oo ");
            else if (minPaths[i] > INT32_MAX)
                printf("INT_MAX+ ");
            else
                printf("%lld ", minPaths[i]);
        }

        restorePath(matrix, minPaths, amountOfVertices, vertexBegin, vertexEnd);
    }
    else if (vertexBegin != vertexEnd)
        printf("0 oo\nno path\n");
    else
       printf("0\n%hd\n", vertexBegin);

    free(minPaths);
    free(summitVertices);
}
// -----------------------------------------------------
// |          Freeing the connection matrix            |
// -----------------------------------------------------
void freeMatrix(int32_t **matrix, int16_t amountOfVertices) {
    for (int16_t i = 0; i < amountOfVertices; i++)
        free(matrix[i]);

    free(matrix);
}