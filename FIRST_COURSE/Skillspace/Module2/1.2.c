#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>


void scanArr(int* arr, int lenArr) {
    for (int i = 0; i < lenArr; i++)
        scanf_s("%d", (arr + i));
}


int minNum(int* arr, int lenArr) {
    int min = 10000000;
    for (int i = 0; i < lenArr; i++)
        if (min > *(arr + i) && *(arr + i))
            min = *(arr + i);
    return min;
}


void printGCD(int* arr, int lenArr) {
    int count = 0, max = 0;
    for (int i = 1; i <= minNum(arr, lenArr); i++) {
        for (int j = 0; j < lenArr; j++)
            if (!(*(arr + j) % i))
                count++;
        if (count == lenArr)
            max = i;
        count = 0;
    }
    printf("%d", max);
}


int main() {
    int lenArr;

    scanf_s("%d", &lenArr);

    int* arr = (int*)malloc(lenArr * sizeof(int));

    scanArr(arr, lenArr);
    printGCD(arr, lenArr);
    free(arr);

    return 0;
}