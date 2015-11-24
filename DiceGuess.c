/*
 * What is Dice Guess?
 * Dice Guess is a game 
 * in which a total of all dice is given to users
 * now they have to select that the next dice roll
 * total will be higher or lower than previous one
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define SUCCESS 0

int main() {
	
	int dice_roll = 0, result_roll = 0, result_roll1 = 0;
	char ans;
	
	/*
	 * To make randomisation independent of fixed system seed
	 */
	srand(time(NULL));
	
	for(int i=0; i<3; i++) {
		dice_roll = (rand() % 6) + 1;
		printf("Dice Rollling .. ... \n");
		printf("Dice Value is: %d \n", dice_roll);
		result_roll += dice_roll;
	}
	// To Store Result Roll
	result_roll1 = result_roll;
	printf("Current total of Dice Roll is : %d \n", result_roll1);
	printf("Now You have to guess next roll will be higher? or lower? compared to current one \n");
	printf("To represent higher press ['h'], To Represent lower press ['l'] \n");
	scanf("%c", &ans);
	
	// Reset Roll counter and re-roll
	result_roll = 0;
	for(int i=0; i<3; i++) {
		dice_roll = (rand() % 6) + 1;
		printf("Dice Rollling .. ... \n");
		printf("Dice Value is: %d \n", dice_roll);
		result_roll += dice_roll;
	}
	printf("Current total of Dice Roll is : %d \n", result_roll);
	
	if(result_roll > result_roll1) {
		if(ans == 'h' || ans == 'H') {
			printf("Your Guess was Right! It is Indeed Higher \n");
		}
		else {
			printf("Sorry, Your Guess was Wrong! It is Lower. \n");
		}	
	}
	else if(result_roll < result_roll1) {
		if(ans == 'l' || ans == 'L') {
			printf("Your Guess was Right! It is Indeed Lower \n");
		}
		else {
			printf("Sorry, Your Guess was Wrong! It is Higher. \n");
		}
	}
	else {
		// Blank cause why the heck not?
	}
	
	return SUCCESS;
}
