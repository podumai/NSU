#include "lab6_0.h"


int32_t* init_arr(int32_t N) {
    int32_t* arr;

    arr = (int32_t*)malloc(sizeof(int32_t) * N);

    return arr;
}


Node* create_node(int32_t num, Node* tree, int32_t index) {
    tree[index].key = num;
    tree[index].left = tree[index].right = 0;

    return &tree[index];
}


int16_t height(Node* p) {
    int16_t height_l, height_r;

    height_l = height_r = 0;

    if (!p)
        return -1;

    height_l = height(p->left);
    height_r = height(p->right);

    return 1 + height_l>height_r?height_l:height_r;
}


int16_t balance_factor(Node* p) {
    if (p)
        return height(p->right) - height(p->left);

    return 0;
}


Node* rotate_r(Node* p) {
    Node* q;

    q = p->left;

    p->left = q->right;
    q->right = p;

    return q;
}


Node* rotate_l(Node* q) {
    Node* p;

    p = q->right;

    q->right = p->left;
    p->left = q;

    return p;
}


Node* balance(Node* p) {
    int16_t balance;

    balance = balance_factor(p);

    if (balance == 2) {
        if (balance_factor(p->right) < 0)
            p->right = rotate_r(p->right);

        return rotate_l(p);
    }
    else if (balance == -2) {
        if (balance_factor(p->left) > 0)
            p->left = rotate_l(p->left);

        return rotate_r(p);
    }

    return p;
}


Node* insert(Node* p, Node* tree, int32_t k) {
    if (!tree)
        return create_node(k, tree, 0);

    if (k < tree->key)
        p->left = insert(p->left, tree, k);
    else
        p->right = insert(p->right, tree, k);

    return balance(p);
}


void input(int32_t* arr, Node* p, Node* tree, int32_t N) {
    for (int32_t i = 0; scanf_s("%d", &arr[i]) == 1 && i < N; i++) {
        create_node(arr[i], tree, i);
        p = insert(p, tree, arr[i]);
    };
}


void search(Node* p, int32_t k) {
    if (!p)
        printf("False\n");
    else if (p->key == k)
        printf("True\n");
    else if (p->key < k)
        search(p->left, k);
    else
        search(p->right, k);
}


void sym_order(Node* p) {
    if (p->left) {
        sym_order(p->left);
    }

    printf("%d\n", p->key);

    if (p->right) {
        sym_order(p->right);
    }
}