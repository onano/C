/*
 * What is Guess Game?
 * Guess Game is a intutive game.. in which
 * there are three people "guess a number"
 * between 0-10 and if their guess matches 
 * system guess then they win.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define SUCESS 0
#define FAIL 1

int main(){
	
	int p1, p2, p3;
	int cmp_guess;
	/*
	 * To make randomisation independent of fixed system seed
	 */
	srand(time(NULL));
	
	printf("Players Enter your Guess [1-10] : \n");
	scanf(" %d %d %d", &p1, &p2, &p3);
	
	if(p1 > 10 || p2 > 10 || p3 > 10) {
		printf("Wrong input resetting .. \n");
		return FAIL;
	}
	
	printf("Checking your Guess.... \n");
	
	cmp_guess = (rand() % 10) + 1;
	printf("Computer's Guess is : %d \n", cmp_guess);
	
	if(cmp_guess == p1) {
		printf("Player 1 won! \n");
	}
	else if(cmp_guess == p2) {
		printf("Player 2 won! \n");
	}
	else if(cmp_guess == p3) {
		printf("Player 3 won! \n");
	}
	else {
		printf("Oh.. Y'all Lost.. \n");
	}
	
	return SUCESS;
}
