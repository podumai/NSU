#include "lab3_1.h"

// Function for initialize an array
int32_t* init_arr(int32_t N) {
    int32_t* arr;

    arr = (int32_t*)malloc(sizeof(int32_t) * N);

    return arr;
}

// Function for input
void input(int32_t* arr, int32_t N) {
    for (int32_t i = 0 ; scanf_s("%d", &arr[i]) && i < N ; i++);
}

// Function to swap two array elements
void swap(int32_t* num1, int32_t* num2) {
    int32_t ptr;

    ptr = *num1;

    *num1 = *num2;
    *num2 = ptr;
}

// Function to split an array
int32_t split(int32_t* arr, int32_t low, int32_t high) {
    int32_t pivot, i, j;

    pivot = arr[(high + low) / 2], i = low, j = high;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i >= j) {
            break;
        }

        swap(&arr[i++], &arr[j--]);
    }

    return j;
}

// Quick sort function
void quick_sort(int32_t* arr, int32_t low, int32_t high) {
    if (low < high) {
        int32_t pivot;

        pivot = split(arr, low, high);

        quick_sort(arr, low, pivot);
        quick_sort(arr, pivot + 1, high);
    }
}

// Function for print sorted array
void output(int32_t* arr, int32_t N) {
    quick_sort(arr, 0, N - 1);

    for (int32_t i = 0 ; i < N ; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
