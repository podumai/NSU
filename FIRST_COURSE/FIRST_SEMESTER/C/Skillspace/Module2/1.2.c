#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>


void scanArr(int * arr, int lenArr) {
    for (int i = 0; i < lenArr; i++)
        scanf_s("%d", &arr[i]);
}


int maxNum(int * arr, int lenArr) {
    int max = 0;
    for (int i = 0; i < lenArr; i++)
        if (max < arr[i])
            max = arr[i];
    return max;
}


int minNum(int * arr, int lenArr) {
    int min = 10000000;
    for (int i = 0; i < lenArr; i++)
        if (min > arr[i] && arr[i])
            min = arr[i];
    return min;
}


void printGCD(int * arr, int lenArr) {
    int count = 0, k = 0;
    int * dividers = (int*)malloc(sizeof(int) * (minNum(arr, lenArr)));
    for (int i = 1; i <= minNum(arr, lenArr); i++) {
        for (int j = 0; j < lenArr; j++)
            if (!(arr[j] % i))
                count++;
        if (count == lenArr)
            dividers[k++] = i;
        count = 0;
    }
    printf("%d", maxNum(dividers, k));
    free(dividers);
}


int main() {
    int lenArr;

    scanf_s("%d", &lenArr);

    int * arr = (int*)malloc(sizeof(int) * lenArr);

    scanArr(arr, lenArr);
    printGCD(arr, lenArr);
    free(arr);

    return 0;
}
