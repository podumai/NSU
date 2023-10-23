#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
	int N, K, M;

	scanf("%d %d %d", &N, &K, &M);

	if (abs(K - M) - 1 > N - M + K - 1)
		printf("%d", N - M + K - 1);
	else
		printf("%d", abs(K - M) - 1);

	return 0;
}