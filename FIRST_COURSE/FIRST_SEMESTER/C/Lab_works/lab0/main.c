#define SIZE 100


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


void upper_case(char * str) {
    for (int i = 0; i < strlen(str); i++)
        if (str[i] >= 'a' && str[i] <= 'f')
            str[i] = toupper(str[i]);
}

void cln(char * str) {
    str[0] = '\0';
}


int check_dot(char * str) {
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == '.')
            return i;

    return 0;
}


void zeroes(char * str) {
    int count = 0;

    if (check_dot(str))
        for (int i = check_dot(str) + 1; i < strlen(str); i++)
            if (str[i] == '0')
                count++;

    if (strlen(str) - (check_dot(str) + 1) == count)
        str[check_dot(str)] = '\0';
}


int check_nums(int a, int b) {
    if (a >= 2 && a <= 16 && b >= 2 && b <= 16)
        return 1;

    return 0;
}


int check_str(char * str, int a) {
    int count = 0, dot = 0;

    if (check_dot(str) || str[0] == '.') {
        int zero = 0;
        int count_b = 1;

        for (int i = 0; i < strlen(str); i++) {
            if (i > check_dot(str) && str[i] == '0')
                zero++;
            else if (i < check_dot(str) && str[i] != '0')
                count_b++;
        }

        if (zero + check_dot(str) + 1 == strlen(str) && count_b - 1 == 0)
            return 0;
    }

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] < a + '0')
            count++;
        else if (str[i] == '.' && dot < 3)
            dot++;
    }

    if (a > 9)
        for (int i = 0; i < strlen(str); i++)
            if (str[i] >= 'A' && str[i] < a + '7')
                count++;

    if (!dot && count == strlen(str))
        return 1;
    else if (dot < 2 && count + dot == strlen(str))
        return 1;

    return 0;
}


void num_sys10(char * str, int a) {
    zeroes(str);

    if (!check_dot(str)) {
        long long int sum = 0;
        int j = strlen(str);

        for (int i = 0; i < strlen(str); i++) {
            j--;

            if (str[i] <= '9')
                sum += (str[i] - '0') * pow(a, j);
            else
                sum += (str[i] - '7') * pow(a, j);
        }

        cln(str);
        _snprintf(str, SIZE, "%lld", sum);
    }
    else {
        int j = check_dot(str);
        double sum_d = 0.;

        for (int i = 0; i < check_dot(str); i++) {
            j--;

            if (str[i] <= '9')
                sum_d += (str[i] - '0') * pow(a, j);
            else
                sum_d += (str[i] - '7') * pow(a, j);
        }

        j = 0;

        for (int i = check_dot(str) + 1; i < strlen(str); i++) {
            j--;

            if (str[i] <= '9')
                sum_d += (str[i] - '0') * pow(a, j);
            else
                sum_d += (str[i] - '7') * pow(a, j);
        }

        cln(str);
        _snprintf(str, SIZE, "%lf", sum_d);
    }
}


void num_sys(char * str, int a) {
    long long int num = atoll(str), num_str = 0;
    long long int t[SIZE];
    int i = 0;

    if (num == 0)
        putchar(num + '0');

    while (num != 0) {
        num_str = num % a;
        num = num / a;
        t[i++] = num_str;
    }

    for (int j = i - 1; j >= 0; j--) {
        if (t[j] < 10)
            putchar(t[j] + '0');
        else
            putchar(t[j] + '7');
    }

    if (check_dot(str)) {
        char * strend = 0;
        long double num_d = strtold(str, strend);

        num = atoll(str);
        num_d -= num;

        putchar('.');

        for (i = 0; i < 12; i++) {
            num_d *= a;
            num = num_d;

            if (num < 10)
                putchar(num + '0');
            else
                putchar(num + '7');
        }
    }
}

int main() {
    char str[SIZE];
    int b1, b2;

    scanf_s("%d%d\n", &b1, &b2);
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    upper_case(str);

    if (check_nums(b1, b2) && check_str(str, b1)) {
        num_sys10(str, b1);
        num_sys(str, b2);
    }
    else
        printf("bad input");

    return 0;
}
