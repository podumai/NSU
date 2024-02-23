#pragma once


#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>



#ifndef CHECK_CURR_SIZE_H_
#define CHECK_CURR_SIZE_H_
int8_t check_curr_size(int16_t size, int16_t curr_size);
#endif


#ifndef CHECK_SIZE_H_
#define CHECK_SIZE_H_
void check_size(int16_t size);
#endif


#ifndef CHECK_NUMS_H_
#define CHECK_NUMS_H_
int8_t check_nums(int64_t *in, int16_t size);
#endif


#ifndef CHECK_SUM_H_
#define CHECK_SUM_H_
int8_t check_sum(int64_t *in, int16_t size);
#endif


#ifndef SUM_H_
#define SUM_H_
int64_t sum(int64_t *in, int16_t size);
#endif


#ifndef INPUT_H_
#define INPUT_H_
int64_t *input(int16_t size);
#endif


#ifndef OUTPUT_H_
#define OUTPUT_H_
void output(int64_t *in, int16_t size);
#endif