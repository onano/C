/*
 * NameFixer is a program for taking a name and 
 * fixing it
 * means if name is entered like onano sama
 * it will convert it to : Onano Sama
 * why? cause why the heck not?
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
	
	char fname[20], lname[30];

	printf("Enter Your first name : ");
	scanf("%s", fname);
	
	printf("\nEnter Your Last name : ");
	scanf("%s", lname);
	
	if(islower(fname[0]) || islower(lname[0])) {
		fname[0] = toupper(fname[0]);
		lname[0] = toupper(lname[0]);
		printf("\nYour name is now fixed and entered to database as : %s %s", fname, lname);
	}
	else {
		printf("\nYour name is entered to database : %s %s", fname, lname);
	}
	
	return 0;
}
