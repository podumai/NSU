#include "lab_begin.h"

// Check size of array in range of 1 -- 10
void check_size(int16_t size) {
    if (size < 1 || size > 10) {
        printf("bad input\n");
    }
}

// Check array in range of INT_MIN -- INT_MAX
int8_t check_nums(int64_t *in, int16_t size) {
    for (int16_t i = 0 ; i < size ; i++) {
        if (in[i] > INT32_MAX || in[i] < INT32_MIN) {
            return 0;
        }
    }

    return 1;
}

//Check sum of array elements in range INT_MIN -- INT_MAX
int8_t check_sum(int64_t *in, int16_t size) {
    int64_t sum;

    sum = 0;

    for (int16_t i = 0 ; i < size ; i++) {
        sum += in[i];
    }

    if (sum < INT32_MIN || sum > INT32_MAX) {
        printf("overflow\n");
        free(in);

        return 0;
    }

    return 1;
}

// Sum function for array elements
int64_t sum(int64_t *in, int16_t size) {
    int64_t sum;

    sum = 0;

    for (int16_t i = 0 ; i < size ; i++) {
        sum += in[i];
    }

    return sum;
}

// Check current size of an array after input
int8_t check_curr_size(int16_t size, int16_t curr_size) {
    if (curr_size < size) {
        printf("bad input\n");

        return 0;
    }

    return 1;
}

// Input function with init array
int64_t *input(int16_t size) {
    int64_t *in;
    int16_t i;

    in = (int64_t*)calloc(size, sizeof(int64_t));
    i = 0;

    check_size(size);

    if (!in) {
        return in;
    }

    for (i = 0 ; scanf_s("%lld", &in[i]) == 1 && i < size ; i++);

    if (!check_curr_size(size, i)) {
        free(in);
    }

    return in;
}

// Output function with several checks
void output(int64_t *in, int16_t size) {
    if (in) {
        if (check_nums(in, size) && check_sum(in, size)) {
            printf("%lld\n", sum(in, size));
        }
        else {
            printf("bad input\n");
        }
    }
}