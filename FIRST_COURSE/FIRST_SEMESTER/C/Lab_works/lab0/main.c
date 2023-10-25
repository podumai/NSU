#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int check_str(char * str, int a) {
    int count = 0, dot = 0;

   if (a >= 2 && a <= 10) {
       for (int i = 0; i < strlen(str); i++) {
           if (str[i] < a + 48 && str[i] >= '0')
               count++;
           else if (str[i] == '.')
               dot++;
       }
   }
   else if (a >= 11 && a <= 16) {
       for (int i = 0; i < strlen(str); i++) {
           if ((str[i] < a + 55 && str[i] >= 'A') ||
           (str[i] >= '0' && str[i] <= '9'))
               count++;
           else if (str[i] == '.')
               dot++;
       }
   }

    if (count + dot == strlen(str) && dot < 2 && ((str[0] != '.' ||
    str[strlen(str) - 1] != '.') || str[0] != '0'))
        return 1;

    return 0;
}


int check_dot(char * str) {
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == '.')
            return i;

    return 0;
}


int check_nums(int a, int b) {
    if (a >= 2 && a <= 16 && b >= 2 && b <= 16)
        return 1;

    return 0;
}


int upper_case(char * str) {
    for (int i = 0; i < strlen(str); i++)
        if (str[i] >= 'a' && str[i] <= 'f')
            str[i] = toupper(str[i]);

    return 0;
}

char num_system10(char * str1, char * str2, int a) {
    int sum_i = 0, j = -1;
    double sum_d = 0.;

    if (!check_dot(str1)) {
        for (int i = strlen(str1) - 1; i >= 0; i--) {
            j++;

            if (str1[i] >= 'A' && str1[i] <= 'F')
                sum_i += (str1[i] - '7') * pow(a, j);
            else
                sum_i += (str1[i] - '0') * pow(a, j);
        }

        snprintf(str2, sizeof(str2), "%d", sum_i);
    }
    else {
        for (int i = check_dot(str1) - 1; i >= 0; i--) {
            j++;
            if (str1[i] >= 'A' && str1[i] <= 'F')
                sum_d += (str1[i] - '7') * pow(a, j);
            else
                sum_d += (str1[i] - '0') * pow(a, j);
        }
        j = 0;

        for (int i = check_dot(str1) + 1; i < strlen(str1); i++) {
            j--;
            if (str1[i] >= 'A' && str1[i] <= 'F')
                sum_d += (str1[i] - '7') * pow(a, j);
            else
                sum_d += (str1[i] - '0') * pow(a, j);

        snprintf(str2, sizeof(str2), "%lf", sum_d);
        }
    }

    return *str2;
}


int cln(char * str) {
    for (int i = 0; i < strlen(str) - 1; i++)
        str[i] = ' ';

    return 0;
}


int put_str(char * str) {
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] < '0' || str[i] > 'F' || (str[i] > '9' && str[i] < 'A')) && str[i] != '.')
            return 0;

        putchar(str[i]);
    }

    return 0;
}


double num_system(char * str, int a) {
    char * strend;
    int t[SIZE];
    int i = 0, num_str = 0, dot = check_dot(str), num = atoi(str);
    double num_e = strtod(str, strend);

    cln(str);

    while (num != 0) {
        num_str = num % a;
        t[i] = num_str;
        i++;
        num /= a;

        if (num / a == 0)
            t[i] = num;
    }

    int k = 0;

    for (int j = i - 1; j >= 0; j--) {
        if (t[j] >= 0 && t[j] <= 9)
            putchar(t[j] + '0');
        else
            putchar(t[j] + '7');

        k++;
    }

    if (dot) {
        num_e -= num;
        putchar('.');

        for (int j = 0; j < 12; j++) {
            num_e *= a;
            num = num_e;
            if (num >= 0 && num <= 9)
                putchar(num + '0');
            else
                putchar(num + '7');
            num_e -= num;
        }
    }

    return *str;
}


void main() {
    int b1, b2;
    char str[SIZE], str_n[SIZE];

    scanf("%d%d\n", &b1, &b2);
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    upper_case(str);

    if (check_nums(b1, b2) == 1 && check_str(str, b1) == 1) {
            num_system10(str, str_n, b1);
            num_system(str_n, b2);
            //put_str(str_n);
    }
    else
        printf("bad input");

    exit(0);
}