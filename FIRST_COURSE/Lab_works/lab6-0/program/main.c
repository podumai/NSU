#include "lab6_0.h"


int32_t main() {
    Node *root, *tree;
    int32_t* arr;
    int32_t N, val;

    root = tree = arr = NULL;
    N = val = 0;

    scanf_s("%d", &N);
    arr = init_arr(N);

    if (arr) {
        input(arr, root, tree, N);
        printf("%hd\n", height(root) + 1);
        sym_order(root);
    }
    else
        printf("Array initialization error\n");

    scanf_s("%d", &val);
    search(root, val);

    free(arr);
    free(tree);
    system("pause");

    return 0;
}