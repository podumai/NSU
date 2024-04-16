// ***************Kosaraju  Algorithm***************
// |   Kosaraju's algorithm is an algorithm for    |
// |  searching for regions of strong connectivity |
// |             in a directed graph.              |
// *************************************************
#include <stdio.h>
#include "messages.h"
#include "functions.h"

int32_t main(void)
{
    Graph *pGraph = NULL;
    Stack *sortVrtx = NULL;

    if (input(&pGraph))
        if (getGraph(&pGraph))
            if (getSort(pGraph, &sortVrtx))
                kosarajuAlgorithm(pGraph, sortVrtx);

    freeGraph(&pGraph);
    freeStack(&sortVrtx);

    printConclusion();

    return 0;
}