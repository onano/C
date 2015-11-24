#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0

int main() {
	
	int arr[5] = {23, 42, 5, 46, 78};
	
	printf("Elements \t Address \t Value \n");
	for(int i =0; i<5; i++) {
		printf("%d \t %p \t %d \n", i, &arr[i], arr[i]);
	}
	
	/*
	 * Array is just a pointer to first element
	 */
	printf("Your array is : %p \n", arr);  
	
	/*
	 * Let's derefernce it
	 */
	printf("Your derefernced array is : %d \n", *arr);
	/*
	 * we can also call values by adding number eg:
	 * now, arr + 2 is: go to memory address to arr
	 * then go to next 2 memory locations
	 * and then derefernce it.
	 * so it goes to 23 then next location 42 and then next 5 
	 * and prints out 5
	 */
	printf("Your derefernced array + 2 is : %d \n", *(arr+2));    
	
	return SUCCESS;
}
