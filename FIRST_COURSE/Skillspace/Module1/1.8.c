#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
	float floors, count_apart, apart;

	scanf("%f %f %f", &floors, &count_apart, &apart);

	float entrance = ceil(apart / count_apart / floors);
	float found_floor = ceil(apart / count_apart) - (entrance - 1) * floors;

	printf("%.f %.f", entrance, found_floor);

	return 0;
}