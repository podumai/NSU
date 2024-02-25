#pragma once


#define SIZE 51


#include <malloc.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


#ifndef INPUT_H_
#define INPUT_H_
char* input(void);
#endif


#ifndef CHECK_IN_H_
#define CHECK_IN_H_
int8_t check_in(char* in);
#endif


#ifndef CHECK_NUM_H_
#define CHECK_NUM_H_
int8_t check_num(char* in);
#endif


#ifndef CHECK_MAX_SWAP_H_
#define CHECK_MAX_SWAP_H_
int8_t check_max_swap(char* in);
#endif


#ifndef SWAP_H_
#define SWAP_H_
void swap(char* in, int32_t index1, int32_t index2);
#endif


#ifndef PERMUTATION_H_
#define PERMUTATION_H_
int8_t permutation(char* in);
#endif


#ifndef OUTPUT_H_
#define OUTPUT_H_
void output(char* in, int32_t N);
#endif
