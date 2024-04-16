// *************************************************
// |  Implementation of functions for displaying   |
// |          information on the screen            |
// *************************************************
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "messages.h"
#include "error.h"
// *************************************************
// |   Displaying information about the program    |
// *************************************************
void printIntroduction(void)
{
    printf("\
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\
|     __ __   ____   _____   ___     ____    ___        __  __  __|\n\
|    / //_/  / __ \\ / ___/  /   |   / __ \\  /   |      / / / / / /|\n\
|   / ,<    / / / / \\__ \\  / /| |  / /_/ / / /| | __  / / / / / / |\n\
|  / /\\ \\  / /_/ / ___/ / / ___ | / _, _/ / ___ |/ /_/ / / /_/ /  |\n\
| /_/  \\_\\ \\____/ /____/ /_/  |_|/_/ |_| /_/  |_|\\____/  \\____/   |\n\
|    ___     __                         _   __    __              |\n\
|   /   |   / / ______  ____    _____  (_) / /_  / /_    ____ ___ |\n\
|  / /| |  / / / __  / / __ \\  / ___/ / / / __/ / __ \\  / __ `__ \\|\n\
| / ___ | / / / /_/ / / /_/ / / /    / / / / / / / / / / / / / / /|\n\
|/_/  |_|/_/  \\__, /  \\____/ /_/    /_/  \\__/ /_/ /_/ /_/ /_/ /_/ |\n\
|            /____/                                               |\n\
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\
|  Kosaraju's algorithm is an algorithm for searching for regions |\n\
|           of strong connectivity in a directed graph.           |\n\
|-----------------------------------------------------------------|\n\
|                         Restrictions:                           |\n\
|              Maximum number of vertices is: 2047                |\n\
|              Maximum number of edges is: 4188162                |\n\
===================================================================\n");
    return;
}
// *************************************************
// |             Invalid input message             |
// *************************************************
void printMessage(uint8_t mode)
{
    switch (mode)
    {
    case 1:
        printf("\
Enter the number of vertices\n\
Number of vertices is: ");
        break;
    case 2:
        printf("\
-------------------------------------------------------------------\n\
Enter the number of edges\n\
Number of edges is: ");
        break;
    case 3:
        printf("\
-------------------------------------------------------------------\n\
Enter the edges:\n");
        break;
    }
}
// *************************************************
// |  Derivation of strongly connected components  |
// *************************************************
void displaySet(Graph *pGraph, uint16_t *set)
{
    printf("\
-------------------------------------------------------------------\n\
|          The result will be placed in a file \"result.txt\"       |\n");

    FILE *out = fopen("result.txt", "w");

    if (out)
    {

        for (uint16_t i = 0; i < pGraph->vertices; i++)
        {
            int16_t count = 0;

            if (*(set + i))
            {
                fprintf(out, "\
/------------------------------LIST-------------------------------\\\n\
Group: %u\n\
Vertices:\n%u ", *(set + i), i + 1);
                
                for (uint16_t j = i + 1; j < pGraph->vertices; j++)
                {
                    if (!(count % 10) && count)
                        fprintf(out, "\n");

                    if (*(set + i) == *(set + j))
                    {
                        count++;
                        fprintf(out, "%u ", j + 1);
                        *(set + j) = 0;
                    }
                }

                *(set + i) = 0;

                fprintf(out, "\n\
\\-----------------------------------------------------------------/\n");
            }
        }
    }

    if (out)
        fclose(out);
    else
       errorMessage(FILE_ERR);

    return;
}
// *************************************************
// |    Displaying a program completion message    |
// *************************************************
void printConclusion(void)
{
    printf("\
-------------------------------------------------------------------\n\
|                       Exit the program...                       |\n\
-------------------------------------------------------------------\n");
    Sleep(1000);
}