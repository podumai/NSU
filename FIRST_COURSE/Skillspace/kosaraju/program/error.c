// *************************************************
// |      Function for displaying erroneous        |
// |                  information                  |
// *************************************************
#include <stdio.h>
#include "error.h"

void errorMessage(int8_t mode)
{
    switch (mode)
    {
        case 0:
            printf("\
!--------------------------------!--------------------------------!\n\
|                Error occurred: \"Bad input\"                       |\n\
|              Enter \"Y\" to continue or \"N\" otherwise              |\n\
!--------------------------------!--------------------------------!\n");
            break;
        case 1:
            printf("\
!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!\n\
|                Error occurred: \"Bad input\"                      |\n\
|              Enter \"Y\" to continue or \"N\" otherwise             |\n\
!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!\n");
            break;
        case 2:
            printf("\
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\
|               Error occurred: \"Bad input\"                       |\n\
|     A subsequent incorrect value will terminate the program     |\n\
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            break;
        case NONE_PRMTR:
            printf("\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n\
|                Error occurred: \"None parameter\"                 |\n\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n");
            break;
        case BAD_VRTS:
            printf("\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n\
|                Error occurred: \"Bad number of vertices\"         |\n\
|            The number of vertices can not be less than 2        |\n\
|                        or greater than 2047                     |\n\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n");
            break;
        case BAD_EDGS:
            printf("\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n\
|                Error occurred: \"Bad number of edges\"            |\n\
|            The number of edges can not be less than 1           |\n\
|                      or greater than 4188162                   |\n\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n");
            break;
        case BAD_VRTX:
            printf("\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n\
|                Error occurred: \"Bad vertex\"                     |\n\
|            The vertex can not be below 1 or greater than        |\n\
|                       the amount of vertices                    |\n\
|                 The vertex can not contain cycle                |\n\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n");
            break;
        case BAD_LNS:
            printf("\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n\
|                Error occurred: \"Bad number of lines\"            |\n\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n");
            break;
        case INCHR_GRPH:
            printf("\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n\
|                Error occurred: \"Incoherent graph\"               |\n\
|              Continue the work of the program? (Y/N)            |\n\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n");
            break;
        case BAD_INPUT:
            printf("\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n\
|                Error occurred: \"Bad input\"                        |\n\
|              Enter \"Y\" to continue or \"N\" otherwise              |\n\
!--!!--!!--!!--!!--!!--!!--!!--!!-!!--!!--!!--!!--!!--!!--!!--!!--!\n");
            break;
        case GRAPH_ALLOC_ERR:
            printf("\
|*****************************************************************|\n\
|                 Error occurred: \"NULL pointer\"                  |\n\
|              Unable to allocate memory to store the Graph       |\n\
|*****************************************************************|\n");
            break;
        case STACK_ALLOC_ERR:
            printf("\
|*****************************************************************|\n\
|                 Error occurred: \"NULL pointer\"                  |\n\
|               Unable to allocate memory for Stack               |\n\
|*****************************************************************|\n");
            break;
        case VISITED_ALLOC_ERR:
            printf("\
|*****************************************************************|\n\
|                 Error occurred: \"NULL pointer\"                  |\n\
|          Unable to allocate memory to store information         |\n\
|                      about visited vertices                     |\n\
|*****************************************************************|\n");
            break;
        case SET_ALLOC_ERR:
            printf("\
|*****************************************************************|\n\
|                 Error occurred: \"NULL pointer\"                  |\n\
|          Unable to allocate memory to store information         |\n\
|                           about sets                            |\n\
|*****************************************************************|\n");
            break;
        case SORTED_ALLOC_ERR:
            printf("\
|*****************************************************************|\n\
|                 Error occurred: \"NULL pointer\"                  |\n\
|       Unable to allocate memory to store sorted vertices        |\n\
|*****************************************************************|\n");
            break;
        case FILE_ERR:
            printf("\
|*****************************************************************|\n\
|                Error occurred: \"Failed to output in file\"       |\n\
|*****************************************************************|\n");
            break;
    }
}
