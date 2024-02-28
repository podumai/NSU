#pragma once


#define Node struct Node


#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


Node {
    int32_t key;
    Node* left;
    Node* right;
};


#ifndef INIT_ARR_H_
#define INIT_ARR_H_
int32_t* init_arr(int32_t N);
#endif


#ifndef SEARCH_H_
#define SEARCH_H_
void search(Node* p, int32_t k);
#endif


#ifndef SYM_ORDER_H_
#define SYM_ORDER_H_
void sym_order(Node* p);
#endif


#ifndef CREATE_NODE_H_
#define CREATE_NODE_H_
Node* create_node(int32_t num, Node* tree, int32_t index);
#endif


#ifndef INPUT_H_
#define INPUT_H_
void input(int32_t* arr, Node* p, Node* tree, int32_t N);
#endif

#ifndef HEIGHT_H_
#define HEIGHT_H_
int16_t height(Node* p);
#endif


#ifndef BALANCE_FACTOR_H_
#define BALANCE_FACTOR_H_
int16_t balance_factor(Node* p);
#endif


#ifndef ROTATE_R_H_
#define ROTATE_R_H_
Node* rotate_r(Node* p);
#endif


#ifndef ROTATE_L_H_
#define ROTATE_L_H_
Node* rotate_l(Node* p);
#endif


#ifndef BALANCE_H_
#define BALANCE_H_
Node* balance(Node* p);
#endif


#ifndef INSERT_H_
#define INSERT_H_
Node* insert(Node* p, Node* tree, int32_t k);
#endif