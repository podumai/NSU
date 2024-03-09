#pragma once


#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct AVL {
    int8_t height;
    int32_t key;
    struct AVL* left;
    struct AVL* right;
} AVL;


#ifndef LAB6_0_H_
#define LAB6_0_H_


AVL* newElement(int32_t);


AVL* initTree(AVL*, int32_t);


void freeTree(AVL*);


int8_t height(AVL*);


int8_t balanceFactor(AVL*);


void fixHeight(AVL* root);


AVL* rotateRight(AVL*);


AVL* rotateLeft(AVL*);


AVL* balance(AVL*);


AVL* insert(AVL*, int32_t);


#endif