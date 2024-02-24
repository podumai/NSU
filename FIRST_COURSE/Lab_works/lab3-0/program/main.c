#include "lab3_0.h"


int32_t main() {
    int32_t* arr;
    int32_t N;

    arr = NULL;
    N = 0;

    scanf_s("%d", &N);
    arr = init_arr(N);
    input(arr, N);
    output(arr, N);
    free(arr);
    system("pause");

    return 0;
}