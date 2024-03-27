// ----------------------Functions----------------------
// |           Implementation of functions             |
// -----------------------------------------------------
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab8_1.h"
// -----------------------------------------------------
// |           Displays error information              |
// |         depending on the input parameter          |
// -----------------------------------------------------
void errorMessage(int8_t mode) {

    switch (mode) {
        case 1:
            printf("Invalid number of parameters\n");
            break;
        case 2:
            printf("bad number of vertices\n");
            break;
        case 3:
            printf("bad number of edges\n");
            break;
        case 4:
            printf("bad number of lines\n");
            break;
        case 5:
            printf("bad vertex\n");
            break;
        case 6:
            printf("bad length\n");
            break;
        case 7:
            printf("no spanning tree\n");
            break;
        default:
            fprintf(stderr, "Error occurred\nUnable to allocate memory\n");
            break;
    }
}
// -----------------------------------------------------
// |             Check input information:              |
// |             1. Number of parameters               |
// |      2.Number of vertices, number of edges        |
// -----------------------------------------------------
bool input(int16_t *vertices, int16_t *edges) {

    if (scanf("%hd%hd", vertices, edges) == 2) {

        if (*vertices >= MIN_VERTICES && *vertices <= MAX_VERTICES) {

            if (*edges >= MIN_EDGES && *edges <= MAX_EDGES(int16_t, *vertices))
                return true;
            
            errorMessage(3);

            return false;

        }

        errorMessage(2);

    }
    else
        errorMessage(1);

    return false;
}
// -----------------------------------------------------
// |             Check input information:              |
// |                 1. First vertex                   |
// |                2. Second vertex                   |
// |                    3. Weight                      |
// -----------------------------------------------------
bool isValid(int16_t *vrtx1, int16_t *vrtx2, int32_t *len, int16_t *vertices) {

    if (*vrtx1 >= MIN_VERTICES && *vrtx1 <= *vertices)

        if (*vrtx2 >= MIN_VERTICES && *vrtx2 <= *vertices) {

            if (*len >= MIN_LEN && *len <= MAX_LEN)
                return true;
            else {

                errorMessage(6);

                return false;

            }
        }

    errorMessage(5);

    return false;
}
// -----------------------------------------------------
// |            Swap two array elements                |
// |          If vertex1 > vertex2 --> swap            |
// -----------------------------------------------------
void swap(int16_t *vrtx1, int16_t *vrtx2) {
    int16_t ptr = *vrtx1;
    *vrtx1 = *vrtx2;
    *vrtx2 = ptr;
}
// -----------------------------------------------------
// |          Filling arrays with input data           |
// -----------------------------------------------------
bool fillArrays(int16_t *start, int16_t *end, int32_t *weights, int16_t *size,
 int16_t *vertices) {

    int32_t len;
    int16_t vrtx1;
    int16_t vrtx2;

    for (int16_t i = 0; i < *size; i++) {

        if (scanf("%hd%hd%d", &vrtx1, &vrtx2, &len) == 3) {

            if (isValid(&vrtx1, &vrtx2, &len, vertices)) {

                if (vrtx1 > vrtx2)
                    swap(&vrtx1, &vrtx2);

                *(start + i) = vrtx1;
                *(end + i) = vrtx2;
                *(weights + i) = len;

            }
            else
                return false;

        }
        else {

            errorMessage(4);

            return false;

        }
    }

    return true;
}
// -----------------------------------------------------
// |      Creating an array of visited vertices        |
// -----------------------------------------------------
bool *makeVisited(int16_t *size) {

    bool *visited = (bool*)calloc((*size), sizeof(bool));

    if (visited)
        *visited = true;

    return visited;
}
// -----------------------------------------------------
// |           Output minimal spanning tree            |
// -----------------------------------------------------
void output(SPAN_TREE *tree, int16_t *size) {
    for (int16_t i = 0; i < *size - 1; i++)
        printf("%hd %hd\n", (tree + i)->vertex1, (tree + i)->vertex2);
}
// -----------------------------------------------------
// |    Checking vertices: visited or not visited      |
// -----------------------------------------------------
bool check(bool el1, bool el2) {
    if ((!el1 || el2) && (el1 || !el2))
        return true;
    
    return false;
}
// -----------------------------------------------------
// |                 Prim's Algorithm                  |
// -----------------------------------------------------
void primAlgorithm(int16_t *start, int16_t *end, int32_t *weights, int16_t *size,
int16_t *vertices) {
 
    SPAN_TREE *tree = (SPAN_TREE*)malloc(sizeof(SPAN_TREE) * (*size));
    bool *visited = makeVisited(vertices);
    int16_t treeSize = 0;

    if (*size < 2) {

        if (*size)
            errorMessage(7);

        free(visited);

        return;

    }

    int32_t *queue = (int32_t*)malloc(sizeof(int32_t) * (*vertices));
    for (int16_t i = 0; i < *vertices; i++)
        *(queue + i) = INFINITY;

    *queue = 0;

    if (tree && visited) {

        for (int16_t i = 0; i < *size - 1; i++)
            for (int16_t j = i + 1; j < *size; j++)
                if ((*(end + i) == *(start + j) || *(end + i) == *(end + j)) &&
                 *(queue + j) > *(weights + i))
                    *(queue + j) = *(weights + j);
        
        for (int16_t i = 0; i < *vertices - 1; i++) {

            for (int16_t j = 0; j < *size; j++) {

                if (*(weights + j) == *(queue + j) && 
                check(*(visited + *(start + j) - 1), *(visited + *(end + j) - 1))) {

                    if (*(visited + *(end + j) - 1))
                        *(visited + *(start + j) - 1) = true;
                    else
                        *(visited + *(end + j) - 1) = true;
                        
                    (tree + treeSize)->vertex1 = *(start + j);
                    (tree + treeSize)->vertex2 = *(end + j);
                    treeSize++;

                }

            }

        }

        if (treeSize > 1)
            output(tree, &treeSize);
        else
            errorMessage(7);

    }
    else
        errorMessage(20);

    free(tree);
}