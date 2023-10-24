#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int check_str(char* str) {
    int count = 0;

    for (int i = 0; i < strlen(str); i++)
        if (str[i] >= '0' && str[i] <= '9')
            count++;

    if (count == strlen(str))
        return 1;

    return 0;
}


int check_num(char* str) {
    for (int i = 0; i < strlen(str) - 1; i++)

        for (int j = i + 1; j < strlen(str); j++)

            if (str[i] == str[j])
                return 1;

    return 0;
}


int check_max_swap(char * str) {
    int count = 0;

    for (int i = 0; i < strlen(str) - 1; i++)
        if (str[i] > str[i + 1])
            count++;

    if (count == strlen(str) - 1)
        return 1;

    return 0;
}


int dijkstra_algorithm(char * str) {
    if (check_max_swap(str) == 1)
        return 1;

    for (int i = strlen(str) - 1; i > 0; i--)
        if (str[i] > str[i - 1]) {
            char m1 = ':';
            int m2 = 0;

            for (int j = i; j < strlen(str); j++)

                if (str[j] > str[i - 1])

                    if (str[j] < m1) {
                        m1 = str[j];
                        m2 = j;
                    }

            char t = str[i - 1];

            str[i - 1] = str[m2];
            str[m2] = t;

            for (int j1 = i; j1 < strlen(str) - 1; j1++)

                for (int j2 = j1 + 1; j2 <strlen(str); j2++)

                    if (str[j1] > str[j2]) {
                        char rep = str[j1];

                        str[j1] = str[j2];
                        str[j2] = rep;
                    }

            i = 0;
        }

    return 0;
}


int main() {
    int N;
    char p[21];

    fgets(p, sizeof(p), stdin);
    scanf("%d", &N);
    p[strcspn(p, "\n")] = 0;

    if (check_str(p) == 1 && check_num(p) == 0) {

        if (check_max_swap(p) == 0)

            for (int k = 0; k < N; k++) {

                if (dijkstra_algorithm(p) == 1)
                    k = N;
                else
                    puts(p);
            }
    }
    else
        printf("bad input");

    return 0;
}
