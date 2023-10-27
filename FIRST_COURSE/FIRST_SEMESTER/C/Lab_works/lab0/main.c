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


void get_str(char * str, int a) {
    char input = '0';
    int i = 1;
    str[0] = '0';

    while (input != '\n' && i < a) {
        str[i++] = getchar();
        input = str[i - 1];
    }
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


void num_sys(char * str, int a, int b) {
    long long int t[SIZE];
    long long int num_str = 0;

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

        j = 0;

        if (sum == 0)
            putchar('0');

        while (sum != 0) {
            num_str = sum % b;
            sum /= b;
            t[j++] = num_str;
        }

        for (int i = j - 1; i >= 0; i--) {
            if (t[i] < 10)
                putchar(t[i] + '0');
            else
                putchar(t[i] + 'W');
        }
    }
    else {
        double sum_d = 0.;
        int j = check_dot(str);

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

        long long int num = sum_d;
        j = 0;

        while (num != 0) {
            num_str = num % b;
            num /= b;
            t[j++] = num_str;
        }

        for (int i = j - 1; i >= 0; i--) {
            if (t[i] < 10)
                putchar(t[i] + '0');
            else
                putchar(t[i] + 'W');
        }

        sum_d -= (int)sum_d;

        if ((int)sum_d == 0 && !j)
            putchar((int)sum_d + '0');

        putchar('.');

        for (j = 0; j < 12; j++) {
            sum_d *= b;

            if ((int)sum_d < 10)
                putchar((int)sum_d + '0');
            else
                putchar((int)sum_d + 'W');

            sum_d -= (int)sum_d;
        }
    }
}


int main() {
    char str[SIZE];
    int b1, b2;

    scanf_s("%d%d\n", &b1, &b2);
    get_str(str, SIZE);
    str[strcspn(str, "\n")] = 0;
    upper_case(str);

    if (check_nums(b1, b2) && check_str(str, b1)) {
        num_sys(str, b1, b2);
    }
    else
        printf("bad input");

    return 0;
}
