#include "lab6_0.h"


int32_t main() {
    AVL* root = NULL;
    int32_t amount;

    scanf_s("%d", &amount);

    if (amount > 0) {
        root = initTree(root, amount);
        printf("%d\n", height(root) + 1);
        freeTree(root);
    }
    else if (!amount)
        printf("0\n");
    else
        printf("Amount of AVL tree vertices can not be negative\n");

    system("pause");

    return 0;
}
