/*
 * This is a program used for
 * taking a avg of random numbers
 * why? cause why the heck not?
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	int how_many = 0, total = 0;
	int *numbers;
	float avg;
	
	/*
	 * To make randomisation independent of fixed system seed
	 */
	srand(time(NULL));
	
	printf("Enter How many numbers your want to average hoss! \n");
	scanf(" %d", &how_many);
	
	/*
	 * Give us the space computer senpai!
	 */ 
	numbers  = (int *)malloc(how_many * sizeof(int));
	
	printf("Your Generated  %d random numbers are : \n", how_many);
	for(int i=0; i<how_many; i++) {
		numbers[i] = (rand() % 20) + 1;
		printf("%d \n", numbers[i]);
		total += numbers[i];
	}
	/*
	 * Lets get the average
	 */
	avg = (float)total / (float)how_many;
	printf("Your average is : %.2f \n", avg);
	
	/*
	 * Give Allocated memory it back to computer
	 */
	free(numbers);
}
