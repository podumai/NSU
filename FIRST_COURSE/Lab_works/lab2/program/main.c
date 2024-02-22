#include "lab2.h"


int32_t main()
{
    int32_t N = 0;
    char *in = (char*)malloc(sizeof(char) * SIZE);

    in = input();
    scanf_s("%d", &N);
    output(in, N);
    free(in);

    return 0;
}