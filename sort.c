#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SUCCESS 0
#define ARR_MAX 10 

int main() {
	
	int sorted, temp;
	int arr[ARR_MAX];
	
	/*
	 * make randomisation independent of system fixed seed
	 */
	srand(time(NULL));
	 
	for(int i=0; i<ARR_MAX; i++) {
		arr[i] = (rand()%25) + 1;
	}
	
	printf("Your Current Array is : \n");
	for(int i=0; i<ARR_MAX; i++) {
		printf("%d \n", arr[i]);
	}
	
	while(1) {
		sorted = 0;
		for(int i=0; i<ARR_MAX-1; i++) {
			if(arr[i] > arr[i+1]) {
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				sorted = 1;
			}
		}
		if(sorted == 0) {
			break;
		}
	}
	
	printf("Your Sorted Final Array is : \n");
	for(int i=0; i<ARR_MAX; i++) {
		printf("%d \n", arr[i]);
	}

	
	return SUCCESS;
}
