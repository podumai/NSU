#pragma once


#define AVL struct AVL


#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


AVL {
    int32_t key;
    AVL* left;
    AVL* right;
};


#ifndef LAB6_0_H_
#define LAB6_0_H_


AVL* newElement(int32_t);


AVL* initTree(AVL*, int32_t);


void freeTree(AVL*);


int8_t height(AVL*);


int8_t balanceFactor(AVL*);


AVL* rotateRight(AVL*);


AVL* rotateLeft(AVL*);


AVL* balance(AVL*);


AVL* insert(AVL*, int32_t);


#endif
