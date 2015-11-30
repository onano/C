#include <stdio.h>

int main() {
	
	int tuna = 120;
	/*printf("Tuna is : %d \n", tuna);
	printf("Address of tuna is : %p \n", &tuna);
	*/ 

	/*
	 * What is pointer?
	 * pointer is a special variable
	 * used to store memory address.
	 */
	int *p_tuna = &tuna;
	printf("Tuna is : %d \n", tuna);
	printf("Address of tuna is : %p \n", p_tuna);

	printf("p_tuna is : %p \n", p_tuna);
	printf("Address of p_tuna is : %p \n", &p_tuna);
	
	/*
	 * Time to derefernce
	 */
	printf("*p_tuna = %d \n", *p_tuna); 
	*p_tuna = 9090;
	
	printf("*p_tuna = %d \n", *p_tuna);
	printf("tuna = %d \n", tuna);
	

	return 0;
}
