#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int f0(int a, int b) {
	return a + b;
}
int f1(int a, int b) {
	return a - b;
}
int f2(int a, int b) {
	return a * b;
}
int f3(int a, int b) {
	return a / b;
}

int main() {
	int res;
	int (*f[])(int a, int b) = { f0, f1, f2, f3 };
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				for (int l = 0; l < 4; l++) {
					res = f[l](f[k](f[j](f[i](1, 2), 3), 4), 5);
					if (res == 25)
						printf("%d\n", res);
				}

	return 0;
}