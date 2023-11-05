#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


void swap(int * arr, int num1, int num2) {
   int tmp = *(arr + num1);
    *(arr + num1) = *(arr + num2);
    *(arr + num2) = tmp;
}


int split(int * arr, int bordDown, int bordUp) {
    int pivot = arr[bordDown];
    int i = bordDown - 1, j = bordUp + 1;
    while (1) {
        do {
            i++;
        } while(arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr, i, j);
    }
}


void quickSort(int * arr, int bordDown, int bordUp) {
    if (bordDown < bordUp) {
        int pivot = split(arr, bordDown, bordUp);
        quickSort(arr, pivot + 1, bordUp);
        quickSort(arr, bordDown, pivot);
    }
}


void printArr(int * arr, int lenArr) {
    for (int i = 0; i < lenArr; i++)
        printf("%d ", arr[i]);
}


void scanArr(int * arr, int lenArr) {
    for (int i = 0; i < lenArr; i++)
        scanf_s("%d", &arr[i]);
}


int main() {
    int N;

    scanf_s("%d", &N);

    int * arr = (int*)malloc(N * sizeof(int));

    scanArr(arr, N);
    quickSort(arr, 0, N - 1);
    printArr(arr, N);
    free(arr);

    return 0;
}