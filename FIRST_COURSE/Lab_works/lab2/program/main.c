#include "lab2.h"


int32_t main() {
    int32_t N;
    char* in;

    N = 0;
    in = NULL;

    in = input();
    scanf_s("%d", &N);

    if (in) {
        output(in, N);
        free(in);
    }
    else {
        printf("Array initialization error\n");
    }

    system("pause");

    return 0;
}
