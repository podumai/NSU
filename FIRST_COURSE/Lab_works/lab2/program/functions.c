#include "lab2.h"

// Function for input
char* input(void) {
    char* in;

    in = (char*)malloc(sizeof(char) * SIZE);

    if (!in) {
        return in;
    }

    fgets(in, SIZE, stdin);
    in[strcspn(in, "\n")] = 0;

    return in;
}

// Check input for only numbers
int8_t check_in(char* in) {
    int32_t count, len;

    count = 0, len = strlen(in);

    for (int32_t i = 0; i < len; i++) {
        if (in[i] >= '0' && in[i] <= '9') {
            count++;
        }
    }

    if (count == len) {
        return 1;
    }

    return 0;
}

// Check input number for repetitions
int8_t check_num(char* in) {
    int32_t len;

    len = strlen(in);

    for (int32_t i = 0; i < len - 1; i++) {
        for (int32_t j = i + 1; j < len; j++) {
            if (in[i] == in[j]) {
                return 1;
            }
        }
    }

    return 0;
}

// Check for maximum permutation
int8_t check_max_swap(char* in) {
    int32_t count, len;

    count = 0, len = strlen(in);

    for (int32_t i = 0; i < len - 1; i++) {
        if (in[i] > in[i + 1]) {
            count++;
        }
    }

    if (count == len - 1) {
        return 1;
    }

    return 0;
}

// Swap two array elements
void swap(char* in, int32_t index1, int32_t index2) {
    int8_t ptr;

    ptr = in[index1];
    in[index1] = in[index2];
    in[index2] = ptr;
}

// Calls permutations in array *in
int8_t permutation(char* in) {
    if (check_max_swap(in)) {
        return 1;
    }

    int32_t len;

    len = strlen(in);

    for (int32_t i = len - 1; i > 0; i--) {
        if (in[i] > in[i - 1]) {
            char m1;
            int32_t m2;

            m1 = ':';
            m2 = 0;

            for (int32_t j = i; j < len; j++) {
                if (in[j] > in[i - 1] && in[j] < m1) {
                    m1 = in[j];
                    m2 = j;
                }
            }

            swap(in, i - 1, m2);

            for (int32_t j = i; j < len - 1; j++) {
                for (int32_t k = j + 1; k < len; k++) {
                    if (in[j] > in[k]) {
                        swap(in, j, k);
                    }
                }
            }

            return 0;
        }
    }

    return 0;
}

// Function for output
void output(char* in, int32_t N) {
    if (check_in(in) && !check_num(in)) {
        if (!check_max_swap(in)) {
            int32_t i;

            i = 0;

            while (i < N && !permutation(in)) {
                puts(in);

                i++;
            }
        }
    }
    else {
        printf("bad input\n");
    }
}
