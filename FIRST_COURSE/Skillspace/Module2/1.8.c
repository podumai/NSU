#include <stdio.h>
#include <stdlib.h>


void primeNum(int num, int divider) {
	if (divider == 0 || divider == 1) {
		printf("This number is the prime number.");
		exit(0);
	}
	else if (!(num % divider) && divider > 1) {
		printf("This number is not the prime number.");
		exit(0);
	}
	primeNum(num, divider - 1);
}


int main() {
	int num;

	scanf_s("%d", &num);
	primeNum(num, num - 1);

	return 0;
}