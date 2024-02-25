#include "lab_begin.h"


int32_t main() {
    int16_t N;
    int64_t* in;

    N = 0;
    in = NULL;

    scanf_s("%hd", &N);
    in = init_arr(N);

    input(in, N);
    output(in, N);
    free(in);

    system("pause");

    return 0;
}
