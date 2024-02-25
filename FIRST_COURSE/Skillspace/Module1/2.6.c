#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {

	int a, b, c, d, e, f;

	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

	if (a + b + c + d + e + f >= 6 && a + b + c + d + e + f <= 48) {
		if ((abs(a - 2) == e || abs(a + 2) == e) && (abs(b - 1) == f ||
			abs(b + 1) == f)) {
            if ((abs(c - e) == abs(d - f)) || (c == e) || (d == f)) {
                printf("Can`t");
            }
            else
                printf("Can");
        }
        else
            printf("bad input");
	}
	else
		printf("bad input");

	return 0;
}