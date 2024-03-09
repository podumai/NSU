#include "lab6_0.h"


AVL* newElement(int32_t value) {
    AVL* ptr = (AVL*)malloc(sizeof(AVL));

    ptr->left = NULL;
    ptr->right = NULL;
    ptr->key = value;

    return ptr;
}


AVL* initTree(AVL* root, int32_t amount) {
    int32_t num;

    for (int32_t i = 0; i < amount; i++) {
        scanf_s("%d", &num);

        root = insert(root, num);
    }
    return root;
}


void freeTree(AVL* root) {
    if (root) {
       freeTree(root->left);
       freeTree(root->right);
       free(root);
    }
}


int8_t height(AVL* root) {
    if (!root)
        return -1;

    return 1 + max(height(root->left), height(root->right));
}


int8_t balanceFactor(AVL* root) {
    if (root)
        return height(root->right) - height(root->left);

    return 0;
}


AVL* rotateRight(AVL* root) {
    AVL* ptr = root->left;

    root->left = ptr->right;
    ptr->right = root;

    return ptr;
}


AVL* rotateLeft(AVL* root) {
    AVL* ptr = root->right;

    root->right = ptr->left;
    ptr->left = root;

    return ptr;
}


AVL* balance(AVL* root) {
    int16_t balance = balanceFactor(root);

    if (balance == 2) {
        if (balanceFactor(root->right) < 0)
            root->right = rotateRight(root->right);

        return rotateLeft(root);
    }
    else if (balance == -2) {
        if (balanceFactor(root->left) > 0)
            root->left = rotateLeft(root->left);

        return rotateRight(root);
    }

    return root;
}


AVL* insert(AVL* root, int32_t value) {
    if (!root)
        return newElement(value);

    if (value < root->key)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return balance(root);
}
