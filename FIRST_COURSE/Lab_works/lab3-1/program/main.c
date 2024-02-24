#include "lab3_1.h"


int32_t main() {
    int32_t* arr;
    int32_t N;

    N = 0;
    arr = NULL;

    scanf_s("%d", &N);
    arr = init_arr(N);
    
    if (arr) {
        input(arr, N);
        output(arr, N);
        free(arr);
    }
    else {
        printf("Array initialization error\n");
    }

    system("pause");

    return 0;
}