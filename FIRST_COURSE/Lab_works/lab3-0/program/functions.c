#include "lab3_0.h"

// Function to initialize an array
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

// Function for heapify a subtree
void heapify(int32_t* arr, int32_t N, int32_t root) {
    int32_t left, right, largest;

    left = 2 * root + 1;
    right = 2 * root + 2;
    largest = root;

    if (left < N) {
        if (arr[left] > arr[largest]) {
            largest = left;
        }
    }
    
    if (right < N) {
        if (arr[right] > arr[largest]) {
            largest = right;
        }
    }
    
    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        heapify(arr, N, largest);
    }
}

// Heap sort function
void heap_sort(int32_t* arr, int32_t N) {
    for (int32_t i = N / 2 - 1 ; i >= 0 ; i--) {
        heapify(arr, N, i);
    }

    for (int32_t i = N - 1 ; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function for print sorted array
void output(int32_t* arr, int32_t N) {
    heap_sort(arr, N);

    for (int32_t i = 0 ; i < N ; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
