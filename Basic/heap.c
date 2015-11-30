#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0;

int main() {
	
	int i, howMany, total = 0;
	float avg;
	int *numbers;
	
	printf("how many numbers of avg you want hoss? \n");
	scanf(" %d", &howMany);

	/*
	 * Allocate size for our request hoss!
	 */ 
	numbers = (int *)malloc(howMany * sizeof(int));
	printf("Enter it Hoss! \n");
	for(i=0; i<howMany; i++) {
		scanf(" %d", &numbers[i]);
		total += numbers[i];
	}
	avg = (float)total / (float)howMany;
	printf("your avg is : %f \n", avg);
	free(numbers);
	return SUCCESS;
}
