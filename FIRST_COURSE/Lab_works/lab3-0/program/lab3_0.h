#pragma once


#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



#ifndef INIT_ARR_H_
#define INIT_ARR_H_
int32_t* init_arr(int32_t N);
#endif


#ifndef INPUT_H_
#define INPUT_H_
void input(int32_t* arr, int32_t N);
#endif


#ifndef SWAP_H_
#define SWAP_H_
void swap(int32_t* num1, int32_t* num2);
#endif


#ifndef HEAPIFY_H_
#define HEAPIFY_H_
void heapify(int32_t* arr, int32_t N, int32_t root);
#endif


#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_
void heap_sort(int32_t* arr, int32_t N);
#endif


#ifndef OUTPUT_H_
#define OUTPUT_H_
void output(int32_t* arr, int32_t N);
#endif
