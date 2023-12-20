#define SIZE 1001


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void push(Node** top, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    if (*top == NULL)
        return -1;
    int data = (*top)->value;
    Node* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

int precedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

int checkInput(char * infix) {
    int counterBrackets = 0, counterDots = 0, counterSymbols = 0, i = 0;
    int counterOperands = 0;

    while (*(infix + i) != '\n') {
        if (*(infix + i) == '.')
            counterDots++;
        else if (*(infix + i) == '(' || *(infix + i) == ')') {
            counterBrackets++;
            if (*(infix + i) == '(') {
                int j = 0;
                while (*(infix + i + j) != '\0') {
                    if (*(infix + i + j) == ')');
                    counterBrackets++;
                    break;
                }
            }
        }
        else if (*(infix + i) < '(' || *(infix + i) > '9')
            counterSymbols++;
        else if (*(infix + i) >= '0' && *(infix + i) <= '9')
            counterOperands++;
        i++;
    }

    if (counterDots || counterSymbols || counterBrackets % 2 ||
        !counterOperands) {
        printf("syntax error");
        return 1;
    }
    return 0;
}


int calculation(char * infix, char * postfix) {
    if (checkInput(infix)) {
        free(infix);
        free(postfix);
        exit(0);
    }

    Node* stack = NULL;
    int i = 0, j = 0;

    while (*(infix + i) != '\n') {
        if (isdigit(*(infix + i))) {
            int num = 0;
            while (isdigit(*(infix + i))) {
                num = num * 10 + (*(infix + i) - '0');
                i++;
            }
            i--;
            postfix[j++] = num + '0';
        }
        else if (strchr("+-*/", *(infix + i))) {
            while (stack != NULL && precedence(*(infix + i)) <= precedence(stack->value)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, *(infix + i));
        }
        else if (*(infix + i) == '(') {
            push(&stack, *(infix + i));
        }
        else if (*(infix + i) == ')') {
            while (stack->value != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        }
        i++;
    }

    while (stack != NULL) {
        postfix[j++] = pop(&stack);
    }
    *(postfix + j) = '\0';

    for (i = 0; *(postfix + i); i++) {
        if (isdigit(*(postfix + i))) {
            push(&stack, *(postfix + i) - '0');
        }
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);

            if (val1 < 0 || val2 < 0) {
                printf("syntax error");
                exit(0);
            }

            switch (*(postfix + i)) {
            case '+':
                push(&stack, val2 + val1);
                break;
            case '-':
                push(&stack, val2 - val1);
                break;
            case '*':
                push(&stack, val2 * val1);
                break;
            case '/':
                if (val1 == 0) {
                    printf("division by zero");
                    exit(0);
                }
                push(&stack, val2 / val1);
                break;
            }
        }
    }
    return pop(&stack);
}


int main() {
    char * infix = (char*)malloc(SIZE * sizeof(char));
    char * postfix = (char*)malloc(SIZE * sizeof(char));

    fgets(infix, SIZE, stdin);
    printf("%d", calculation(infix, postfix));
    free(infix);
    free(postfix);

    return 0;
}