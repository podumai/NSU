#include <stdio.h>


int digitalRoot(int num) {
	if (num < 10)
		return num;
	int sum = 0;
	while (num) {
		sum += num % 10;
		num /= 10;
	}
	return digitalRoot(sum);
}


int main() {
	int num;

	scanf_s("%d", &num);
	printf("%d", digitalRoot(num));

	return 0;
}