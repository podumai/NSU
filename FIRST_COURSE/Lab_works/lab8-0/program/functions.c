// ----------------------Functions----------------------
// |           Implementation of functions             |
// -----------------------------------------------------

#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "lab8_0.h"

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
        printf("Error occurred\nUnable to allocate memory\n");
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
    if (*vrtx1 > MIN_VERTICES && *vrtx1 <= *vertices)
        if (*vrtx2 > MIN_VERTICES && *vrtx2 <= *vertices) {
            if (*len >= 0 && *len <= INT32_MAX)
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
// |             Initialization of an array            |
// |       that stores information about edges         |
// -----------------------------------------------------
EDGE* createArray(int16_t *size) {
    EDGE* array = (EDGE*)calloc(*size, sizeof(EDGE));

    if (!array)
        errorMessage(20);

    return array;
}
// -----------------------------------------------------
// |               Swap two vertices                   |
// | If vrtx1 > vrtx2 --> vrtx1 = vrtx2, vrtx2 = vrtx1 |
// -----------------------------------------------------
void swapVertex(int16_t *vrtx1, int16_t *vrtx2) {
    int16_t ptr = *vrtx1;
    *vrtx1 = *vrtx2;
    *vrtx2 = ptr;
}
// -----------------------------------------------------
// |        Filling an array with input data           |
// -----------------------------------------------------
bool fillArray(EDGE *array, int16_t *size, int16_t *vertices) {
    int16_t vrtx1;
    int16_t vrtx2;
    int32_t len;

    for (int16_t i = 0; i < *size; i++) {
        if (scanf("%hd%hd%d", &vrtx1, &vrtx2, &len) == 3) {
            if (isValid(&vrtx1, &vrtx2, &len, vertices)) {

                if (vrtx1 > vrtx2)
                    swapVertex(&vrtx1, &vrtx2);
                else if (vrtx1 == vrtx2)
                    (array + i)->status = 1;

                (array + i)->vertex1 = vrtx1;
                (array + i)->vertex2 = vrtx2;
                (array + i)->weight = len;
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
// |            Swap two array elements                |
// |          If weight1 > weight2 --> swap            |
// -----------------------------------------------------
void swapArr(EDGE *element1, EDGE *element2) {
    EDGE ptr = *element1;
    *element1 = *element2;
    *element2 = ptr;
}
// -----------------------------------------------------
// |           Sorting edges by their weights          |
// |              in an ascending order                |
// -----------------------------------------------------
void sortArray(EDGE *array, int16_t *size) {
    bool flag = true;

    for (int16_t i = 0; i < *size - 1 && flag; i++) {
        flag = false;

        for (int16_t j = i + 1; j < *size; j++)
            if ((array + i)->weight > (array + j)->weight) {
                swapArr(array + i, array + j);
                flag = true;
            }
    }
}
// -----------------------------------------------------
// |        Finding an initial suitable vertex         |
// |       which will be taken as the basis for        |
// |              constructing the tree                |
// -----------------------------------------------------
void createTree(SPAN_TREE *tree, EDGE *array, int16_t *size, int16_t *length) {
    for (int16_t i = 0; i < *size; i++)
        if (!((array + i)->status)) {
            (array + i)->status = 1;
            tree->vertex1 = (array + i)->vertex1;
            tree->vertex2 = (array + i)->vertex2;
            *length += 1;

            return;
        }
}
// -----------------------------------------------------
// |       Checking whether an edge is included        |
// |               in a spanning tree                  |
// -----------------------------------------------------
bool inTree(EDGE *array, SPAN_TREE *tree, int16_t *size) {
    for (int16_t i = 0; i < *size; i++)
        if (array->vertex1 == (tree + i)->vertex1 ||
            array->vertex1 == (tree + i)->vertex2
            || array->vertex2 == (tree + i)->vertex1 ||
            array->vertex2 == (tree + i)->vertex2)
            return true;

    return false;
}
// -----------------------------------------------------
// |          Checking for cycle formation             |
// -----------------------------------------------------
bool isCycle(EDGE *array, SPAN_TREE *tree, int16_t *size) {
    int16_t countVrtx1 = 0;
    int16_t countVrtx2 = 0;

    for (int16_t i = 0; i < *size; i++) {
        if ((tree + i)->vertex1 == array->vertex1 ||
            (tree + i)->vertex2 == array->vertex1)
            countVrtx1++;
        else if ((tree + i)->vertex1 == array->vertex2 ||
            (tree + i)->vertex2 == array->vertex2)
            countVrtx2++;

        if (countVrtx1 && countVrtx2)
            return true;
    }

    return false;
}
// -----------------------------------------------------
// |              Swap two tree elements               |
// -----------------------------------------------------
void swapTree(SPAN_TREE *element1, SPAN_TREE *element2) {
    SPAN_TREE ptr = *element1;
    *element1 = *element2;
    *element2 = ptr;
}
// -----------------------------------------------------
// |    Sorting edges by position in an edge array     |
// -----------------------------------------------------
void sortTree(SPAN_TREE *tree, int16_t *size) {
    bool flag = true;

    for (int16_t i = 0; i < *size && flag; i++) {
        flag = false;

        for (int16_t j = *size - 1; i < j; j--)
            if ((tree + i)->position > (tree + j)->position) {
                swapTree(tree + i, tree + j);
                flag = true;
            }
    }
}
// -----------------------------------------------------
// |         Check whether the source graph            |
// |           is a minimum spanning tree              |
// -----------------------------------------------------
bool checkTree(SPAN_TREE *tree, EDGE *array, int16_t *size, int16_t *length) {
    int16_t counter = 0;

    for (int16_t i = 0; i < *length; i++)
        if ((tree + i)->vertex1 == (array + i)->vertex1 &&
            (tree + i)->vertex2 == (array + i)->vertex2)
            counter++;

    if (counter == *length && counter == *size)
        return true;
    else
        return false;
}
// -----------------------------------------------------
// |           Output minimal spanning tree            |
// -----------------------------------------------------
void output(SPAN_TREE *tree, int16_t *size) {
    for (int16_t i = 0; i < *size; i++)
        printf("%hd %hd\n", (tree + i)->vertex1, (tree + i)->vertex2);
}
// -----------------------------------------------------
// |                Kruskal's Algorithm                |
// -----------------------------------------------------
void kruskalAlgorithm(EDGE *array, int16_t *size, int16_t *vertices) {
    SPAN_TREE *tree = (SPAN_TREE*)calloc(*vertices, sizeof(SPAN_TREE));
    int16_t length = 0;
    int16_t count = 1;
    int16_t i = 0;

    createTree(tree, array, size, &length);

    if (tree) {
        while (count < *size) {

            if (!((array + i)->status)) {

                if (inTree(array + i, tree, &length)) {

                    if (isCycle(array + i, tree, &length))
                        (array + i)->status = 1;
                    else {
                        (array + i)->status = 1;
                        (tree + length)->position = i + 1;
                        (tree + length)->vertex1 = (array + i)->vertex1;
                        (tree + length)->vertex2 = (array + i)->vertex2;
                        length++;
                    }

                    count++;
                    i = 0;

                    continue;
                }
            }

            i++;
        }

        sortTree(tree, &length);

        if (length > 1 && !checkTree(tree, array, size, &length))
            output(tree, &length);
        else
            errorMessage(7);
    }
    else
        errorMessage(20);

    free(tree);
}