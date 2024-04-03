// ----------------------Functions----------------------
// |           Implementation of functions             |
// -----------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "lab7.h"
// -----------------------------------------------------
// |    Displays a message about the error caused      |
// -----------------------------------------------------
void errorMessage(int8_t mode) {

    switch (mode) {
    case 1:
        fprintf(stderr, "Error occurred: Invalid number of parameters\n");
        break;
    case 2:
        fprintf(stderr, "bad number of vertices\n");
        break;
    case 3:
        fprintf(stderr, "bad number of edges\n");
        break;
    case 4:
        fprintf(stderr, "bad number of lines\n");
        break;
    case 5:
        fprintf(stderr, "bad vertex\n");
        break;
    case 6:
        fprintf(stderr, "Error occurred: Incoherent graph;\n\
Result: Impossible to sort\n");
        break;
    case 7:
        fprintf(stderr, "Error occurred: Cyclic graph;\n\
Result: Impossible to sort\n");
        break;
    default:
        fprintf(stderr, "Error occurred: Unable to allocate memory\n");
        break;
    }

}
// -----------------------------------------------------
// |         Checking initial parameters               |
// -----------------------------------------------------
bool input(int16_t *vertices, int16_t *edges) {

    if (scanf("%hd%hd", vertices, edges) == 2) {

        if (*vertices >= MIN_VERTICES && *vertices <= MAX_VERTICES) {

            if (*edges >= MIN_EDGES && *edges <= MAX_EDGES(int16_t, *vertices)
                && *vertices)
                return true;
            else
                errorMessage(ERR_NUM_EDG);

        }
        else
            errorMessage(ERR_NUM_VERT);
    }
    else
        errorMessage(ERR_NUM_PAR);

    return false;

}
// -----------------------------------------------------
// |        Initializing the adjacency matrix          |
// -----------------------------------------------------
Link *createMatrix(int16_t size) {

    Link *matrix = (Link*)calloc(size * size, sizeof(Link));

    if (!matrix) {

        errorMessage(ALLOC_ERR);
        exit(ALLOC_ERR);

    }

    return matrix;

}
// -----------------------------------------------------
// |       Checking vertices for compliance            |
// -----------------------------------------------------
bool isValid(int16_t vrtx1, int16_t vrtx2, int16_t vertices) {

    if (vrtx1 > MIN_VERTICES && vrtx1 <= vertices && vrtx1 != vrtx2)

        if (vrtx2 > MIN_VERTICES && vrtx2 <= vertices)
            return true;

    errorMessage(ERR_VRTX);

    return false;

}
// -----------------------------------------------------
// |          Filling the adjacency matrix             |
// -----------------------------------------------------
bool fillMatrix(Link *matrix, int16_t vertices, int16_t size) {

    int16_t vrtx1;
    int16_t vrtx2;

    for (int16_t i = 0; i < size; i++) {

        if (scanf("%hd%hd", &vrtx1, &vrtx2) == 2) {

            if (isValid(vrtx1, vrtx2, vertices))
                (matrix + (vrtx1 - 1) * vertices + vrtx2 - 1)->flag = 1;
            else
                return false;

        }
        else {

            errorMessage(ERR_NUM_LNS);

            return false;

        }

    }

    return true;

}
// -----------------------------------------------------
// |               Depth first search                  |
// -----------------------------------------------------
void dfs(Link *matrix, Link *visited, Stack *stack, int16_t size,
    int16_t vrtx) {

    (visited + vrtx)->flag = 1;

    for (int16_t i = 0; i < size; i++)
        if ((matrix + vrtx * size + i)->flag && !(visited + i)->flag)
            dfs(matrix, visited, stack, size, i);

    if (stack->capacity < stack->size)
        *(stack->storage + (stack->capacity)++) = ++vrtx;
    else
        return;

}
// -----------------------------------------------------
// |      Creating a list of visited vertices          |
// -----------------------------------------------------
Link *makeVisited(int16_t size) {

    return (Link*)calloc(size, sizeof(Link));

}
// -----------------------------------------------------
// |     Creating a stack with initial parameters      |
// -----------------------------------------------------
Stack *makeStack(int16_t size) {

    Stack *stack = (Stack*)malloc(sizeof(Stack));

    if (stack) {

        stack->storage = (uint16_t*)calloc(size, sizeof(uint16_t));
        stack->capacity = 0;
        stack->size = size;

    }

    return stack;

}
// -----------------------------------------------------
// |            Searching for cycle in graph           |
// -----------------------------------------------------
int8_t searchCycle(Link *matrix, int16_t size, Link *visited, int16_t start, 
    int16_t vrtx) {

    int8_t result = 0;

    (visited + vrtx)->flag = 1;

    for (int16_t i = 0; i < size; i++) {

        if (!(visited + i)->flag && (matrix + vrtx * size + i)->flag)
            result += searchCycle(matrix, size, visited, start, i);
        else if ((matrix + vrtx * size + start)->flag)
            return -1;

    }

    return result;

}
// ------------------------------------------------------
// |           Check for acyclic graph                  |
// ------------------------------------------------------
bool isCycled(Link *matrix, int16_t size, Link *visited) {

    int8_t result = 0;

    for (int16_t i = 0; i < size; i++)
        if (!(visited + i)->flag)
            result += searchCycle(matrix, size, visited, i, i);

    if (!result)
        return false;
    
    errorMessage(ERR_CYCLED);

    return true;
}
// ------------------------------------------------------
// |    Joining the remaining vertices of the set       |
// ------------------------------------------------------
void connect(Link *matrix, int16_t size, uint16_t *graphTree, int16_t vrtx) {

    for (int16_t i = 0; i < size; i++)
        if ((matrix + vrtx * size + i)->flag ||
            (matrix + i * size + vrtx)->flag)
            *(graphTree + i) = *(graphTree + vrtx);

}
// -----------------------------------------------------
// |        Checking for graph connectivity            |
// -----------------------------------------------------
bool isConnected(Link *matrix, int16_t size) {

    Link *visited = makeVisited(size);
    uint16_t *graphTree = (uint16_t*)malloc(sizeof(uint16_t) * size);
    bool flag = true;

    if (visited && graphTree) {

        for (int16_t i = 0; i < size; i++)
            *(graphTree + i) = i;

        for (int16_t i = 0; i < size; i++)
            if (!(visited + i)->flag) {

                for (int16_t j = 0; j < size; j++)
                    if ((matrix + i * size + j)->flag) {

                        *(graphTree + j) = *(graphTree + i);
                        connect(matrix, size, graphTree, j);
                        (visited + j)->flag = 1;

                    }
                
                (visited + i)->flag = 1;

            }
 
        for (int16_t i = 0; i < size - 1 && flag; i++)
            for (int16_t j = i + 1; j < size && flag; j++)
                if (*(graphTree + i) != *(graphTree + j))
                    flag = false;

        
    }
    else
        errorMessage(ALLOC_ERR);

    free(visited);
    free(graphTree);

    if (!flag)
        errorMessage(ERR_INCHRNT);

    return flag;

}
// -----------------------------------------------------
// |                Topological Sort                   |
// -----------------------------------------------------
void topologicalSort(Link *matrix, int16_t size) {

    Link *visited = makeVisited(size);
    Stack *stack = makeStack(size);

    if (!stack || !visited) {

        if (stack)
            free(stack->storage);

        errorMessage(ALLOC_ERR);
        free(stack);
        free(visited);

        return;

    }

    for (int16_t i = 0; i < size; i++)
        if (!((visited + i)->flag))
            dfs(matrix, visited, stack, size, i);

    while (--stack->capacity >= 0)
        printf("%hd ", *(stack->storage + stack->capacity));

    free(stack->storage);
    free(stack);
    free(visited);

}
