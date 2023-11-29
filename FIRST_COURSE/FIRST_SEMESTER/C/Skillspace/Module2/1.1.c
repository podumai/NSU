#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>


void scanArr(int * arr, int lenArr) {
    for (int i = 0; i < lenArr; i++)
        scanf_s("%d", &arr[i]);
}


void squareRoot(int * arr, int lenArr) {
    for (int i = 0; i < lenArr; i++)
        if (arr[i] == pow(sqrt(arr[i]), 2))
            printf("%d ", arr[i]);
}


int main() {
    int lenArr;

    scanf("%d", &lenArr);

    int * arr = (int*)malloc(sizeof(int)*lenArr);

    scanArr(arr, lenArr);
    squareRoot(arr, lenArr);
    free(arr);

    return 0;
}