/*
 * it's fucking awsome
 */
#include <stdio.h>

int main() {
	
	int day = 1;
	float amount = 0.01;
	
	while(day <= 31) {
		printf("Day %d \t Amount is : %.2f\n", day, amount);
		amount *= 2;
		day += 1; //alternative to day++
	}
	
	return 0;
}
