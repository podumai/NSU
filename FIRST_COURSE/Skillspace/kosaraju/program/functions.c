// *************************************************
// |    Implementation of the functions of the     |
// |                main algorithm                 |
// *************************************************
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "error.h"
#include "messages.h"
// *************************************************
// |              Graph initialization             |
// *************************************************
Graph *makeGraph(int16_t vertices, int32_t edges)
{
    Graph *graph = (Graph*)malloc(sizeof(Graph));

    if (graph)
    {
        graph->matrix = (int8_t*)calloc(vertices * vertices, sizeof(int8_t));
        graph->vertices = vertices;
        graph->edges = edges;

        if (!graph->matrix)
        {
            free(graph->matrix);
            graph->matrix = NULL;
            free(graph);
            graph = NULL;
        }
    }

    if (!graph)
    {
        errorMessage(GRAPH_ALLOC_ERR);
        exit(GRAPH_ALLOC_ERR);
    }

    return graph;
}
// *************************************************
// |             Stack initialization              |
// *************************************************
Stack *makeStack(uint16_t vertices)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    if (stack)
    {
        stack->storage = (uint16_t*)malloc(sizeof(Stack) * vertices);
        stack->capacity = 0;
        stack->size = vertices;

        if (!stack->storage)
        {
            free(stack);
            stack = NULL;
        }
    }

    return stack;
}
// *************************************************
// |  Initializing the array of visited vertices   |
// *************************************************
int8_t *makeVisited(Graph *pGraph)
{
    int8_t *visited = (int8_t*)calloc(pGraph->vertices, sizeof(int8_t));

    if (visited)
        for (uint16_t i = 0; i < pGraph->vertices; i++)
        {
            uint16_t counter = 0;

            for (uint16_t j = 0; j < pGraph->vertices; j++)
                if (*(pGraph->matrix + i * pGraph->vertices + j) ||
                    *(pGraph->matrix + j * pGraph->vertices + i))
                    counter++;

            if (!counter)
                *(visited + i) = -1;
        }
    else
        errorMessage(VISITED_ALLOC_ERR);

    return visited;
}
// *************************************************
// |  Initialization of disjoint sets of vertices  |
// *************************************************
uint16_t *makeSet(Graph *pGraph)
{
    uint16_t *set = (uint16_t*)calloc(pGraph->vertices, sizeof(uint16_t));

    if (set)
        for (uint16_t i = 0; i < pGraph->vertices; i++)
        {
            int16_t counter = 0;

            for (uint16_t j = 0; j < pGraph->vertices; j++)
                if (*(pGraph->matrix + i * pGraph->vertices + j) ||
                *(pGraph->matrix + j * pGraph->vertices + i))
                    counter++;
            
            if (counter)
                *(set + i) = i + 1;
        }
    else
        errorMessage(SET_ALLOC_ERR);

    return set;
}
// *************************************************
// |          Entering vertices and edges          |
// |              Graph initialization             |
// *************************************************
int8_t input(Graph **pGraph)
{
    printIntroduction();
    printMessage(VRTX);

    int16_t vrtx;
    int32_t edgs;

    if (scanf("%hd", &vrtx) == 1)
    {
        if (vrtx <= MIN_VRTX || vrtx > MAX_VRTX)
        {
            errorMessage(BAD_VRTS);
            return 0;
        }
    }
    else
    {
        errorMessage(NONE_PRMTR);
        return 0;
    }

    printMessage(EDGS);

    if (scanf("%d", &edgs) == 1)
    {
        if (edgs <= MIN_EDGES || edgs > MAX_EDGES(int32_t, vrtx))
        {
            errorMessage(BAD_EDGS);
            return 0;
        }
    }
    else
    {
        errorMessage(NONE_PRMTR);
        return 0;
    }

    *pGraph = makeGraph(vrtx, edgs);

    return 1;
}
// *************************************************
// |      Checking the validity of a vertex        |
// *************************************************
int8_t checkVertex(int16_t vrtx1, int16_t vrtx2, uint16_t vertices)
{
    if (vrtx1 != vrtx2 && vrtx1 >= MIN_VRTX && vrtx1 <= vertices)
        if (vrtx2 >= MIN_VRTX && vrtx2 <= vertices)
            return 1;

    return 0;
}
// *************************************************
// |        Filling the graph with values          |
// *************************************************
int8_t getGraph(Graph **pGraph)
{
    printMessage(EDG);

    int16_t vrtx1, vrtx2;

    for (uint32_t i = 0; i < (*pGraph)->edges; i++)
    {
        if (scanf("%hd%hd", &vrtx1, &vrtx2) == 2)
        {
            if (checkVertex(vrtx1, vrtx2, (*pGraph)->vertices))
                *((*pGraph)->matrix + (vrtx1 - 1) *
                 (*pGraph)->vertices + vrtx2 - 1) = 1;
            else
            {
                errorMessage(BAD_VRTX);
                return 0;
            }
        }
        else
        {
            errorMessage(BAD_LNS);
            return 0;
        }
    }

    return 1;
}
// *************************************************
// |    Function for forming a set of vertices     |
// *************************************************
void connectGraph(Graph *pGraph, int8_t *visited, uint16_t *set, uint16_t vrtx,
uint16_t color)
{
    ++*(visited + vrtx);
    *(set + vrtx) = color;

    for (uint16_t i = 0; i < pGraph->vertices; i++)
        if (!*(visited + i) &&
            (*(pGraph->matrix + i * pGraph->vertices + vrtx) ||
                *(pGraph->matrix + vrtx * pGraph->vertices + i)))
            connectGraph(pGraph, visited, set, i, color);

    return;
}
// *************************************************
// |        Checking for graph connectivity        |
// *************************************************
int8_t isConnected(Graph *pGraph)
{
    int8_t *visited = makeVisited(pGraph);
    uint16_t *set = makeSet(pGraph);
    int8_t flag = 1;

    if (!visited || !set)
    {
        free(visited);
        free(set);
        visited = NULL;
        set = NULL;

        return -1;
    }

    for (uint16_t i = 0; i < pGraph->vertices; i++)
        if (!*(visited + i))
            connectGraph(pGraph, visited, set, i, i + 1);

    for (uint16_t i = 0; i < pGraph->vertices - 1 && flag; i++)
        if (*(set + i))
            for (uint16_t j = i + 1; j < pGraph->vertices && flag; j++)
                if (*(set + i) != *(set + j) && *(set + j))
                    --flag;

    free(visited);
    free(set);

    return flag;
}
// *************************************************
// |           Validating user selection           |
// *************************************************
int8_t checkChoice(int8_t choice)
{
    if (choice == 'Y' || choice == 'N')
        return choice;
    
    return 0;
}
// *************************************************
// |     DFS function for topological sorting      |
// *************************************************
void dfs(Graph *pGraph, int8_t *visited, Stack *stack, uint16_t vrtx)
{
    ++*(visited + vrtx);

    for (uint16_t i = 0; i < pGraph->vertices; i++)
        if (!*(visited + i) &&
            *(pGraph->matrix + i * pGraph->vertices + vrtx))
            dfs(pGraph, visited, stack, i);

    *(stack->storage + stack->capacity++) = vrtx;

    return;
}
// *************************************************
// |       Functions to get user selection         |
// *************************************************
void getChoice(int8_t *choice)
{
    int8_t count = 0;
    
    do
    {
        getchar();
        *choice = getchar();
        *choice = toupper(*choice);

        if (!( *choice = checkChoice(*choice)) && count < 3)
            errorMessage(count++);
        else if (!(*choice))
        {
            errorMessage(count);
            *choice = 'N';
        }
    } while (!(*choice) && count < 4);

    return;
}
// *************************************************
// |   Function to run DFS on an inverted graph    |
// |             to order the vertices             |
// *************************************************
int8_t getSort(Graph *pGraph, Stack **sortVrtx)
{
    Stack *stack = makeStack(pGraph->vertices);
    int8_t *visited = makeVisited(pGraph);
    *sortVrtx = makeStack(pGraph->vertices);
    int8_t choice = 'Y';
    int8_t res;

    if (!stack || !visited || !sortVrtx)
    {
        freeStack(&stack);
        free(visited);
        freeStack(sortVrtx);
        visited = NULL;
        return 0;
    }

    if (!(res = isConnected(pGraph)))
    {
        errorMessage(INCHR_GRPH);

        getChoice(&choice);
    }

    if (choice == 'Y' && res >= 0)
    {
        for (uint16_t i = 0; i < pGraph->vertices; i++)
            if (!*(visited + i))
                dfs(pGraph, visited, stack, i);

        while (--stack->capacity >= 0)
            *((*sortVrtx)->storage + (*sortVrtx)->capacity++) =
             *(stack->storage + stack->capacity);
    }
    
    freeStack(&stack);
    free(visited);
    
    if (choice == 'Y' && res >= 0)
        return 1;

    return 0;
}
// *************************************************
// |   DFS function to check whether a vertex is   |
// |    included in a set of strongly connected    |
// |                     graph                     |
// *************************************************
uint16_t findScc(Graph *pGraph, int8_t *visited, uint16_t vrtx, uint16_t start)
{
    ++*(visited + vrtx);
    int16_t result = 0;

    if (*(pGraph->matrix + vrtx * pGraph->vertices + start))
            return 1;

    for (uint16_t i = 0; i < pGraph->vertices; i++)
        if (!*(visited + i) &&
         *(pGraph->matrix + vrtx * pGraph->vertices + i))
            result += findScc(pGraph, visited, i, start);

    return result;
}
// *************************************************
// |    Clearing the array of visited vertices     |
// *************************************************
void refreshVisited(int8_t *visited, Graph *pGraph)
{
    for (uint16_t i = 0; i < pGraph->vertices; i++)
    {
        int16_t count = 0;

        for (uint16_t j = 0; j < pGraph->vertices; j++)
            if (*(pGraph->matrix + i * pGraph->vertices + j) ||
            *(pGraph->matrix + j * pGraph->vertices + i))
                count++;
        
        if (count)
            *(visited + i) = 0;
    }

    return;
}
// *************************************************
// |             Kosaraju's algorithm              |
// *************************************************
void kosarajuAlgorithm(Graph *pGraph, Stack *sortVrtx)
{
    int8_t *visited = makeVisited(pGraph);
    uint16_t *set = makeSet(pGraph);
    uint16_t result;
  
    for (uint16_t i = 0; i < pGraph->vertices; i++)
        for (uint16_t j = 0; j < pGraph->vertices; j++)
            if (*(pGraph->matrix + *(sortVrtx->storage + i)
             * pGraph->vertices + j))
            {   
                if ((result = 
                findScc(pGraph, visited, j, *(sortVrtx->storage + i))))
                    *(set + *(sortVrtx->storage + i)) = *(set + j);
                
                refreshVisited(visited, pGraph);
            }

    displaySet(pGraph, set);

    return;
}
// *************************************************
// |      Freeing memory allocated for storing     |
// |                    a graph                    |
// *************************************************
void freeGraph(Graph **pGraph)
{
    if (*pGraph)
    {
        if ((*pGraph)->matrix)
        {
            free((*pGraph)->matrix);
            (*pGraph)->matrix = NULL;
        }
        free(*pGraph);
        *pGraph = NULL;
    }

    return;
}
// *************************************************
// |  Freeing memory allocated for stack storage   |
// *************************************************
void freeStack(Stack **stack)
{
    if (*stack)
    {
        if ((*stack)->storage)
        {
            free((*stack)->storage);
            (*stack)->storage = NULL;
        }
        free(*stack);
        *stack = NULL;
    }

    return;
}
