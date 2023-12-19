#include <stdio.h>
#include <stdlib.h>


int sumNum(int num) {
	if (num <= 0)
		return 0;
	return(num % 10 + sumNum(num / 10));
}


int main() {
	int num;

	scanf_s("%d", &num);
	printf("%d", sumNum(num));

	return 0;
}