/*
 * FinalFiles is a simple program to create some files
 * and read and append information from it
 * ONLY FOR SEQUENTIAL FILES! (for now) 
 * why? cause why the heck not?
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	char *pline;
	FILE *fptr;
	/*
	 * Let's create and write the file
	 */
	fptr = fopen("Lyrics.txt", "w");
	fprintf(fptr, "Hey This is inital file..");
	//close the file after writing it
	fclose(fptr); 
	
	/*
	 * Displaying the info on cmd screen
	 */ 
	fptr = fopen("Lyrics.txt", "r");
	pline = (char *)malloc(200 * sizeof(char));
	while(1) {
		fgets(pline, 200, fptr);
			puts(pline);
		if(feof(fptr)) {
			break;
		}
	}
	fclose(fptr);
	free(pline);
	/*
	 * We will append that Lyrics.txt
	 */
	fptr = fopen("Lyrics.txt", "a");
	fprintf(fptr, "\nhere we have a simple line");
	fprintf(fptr, "\nhere we have another simple line");
	//close the file
	fclose(fptr);
	 
	/*
	 * display new modified file 
	 */ 
	fptr = fopen("Lyrics.txt", "r");
	pline = (char *)malloc(200 * sizeof(char));
	while(1) {
		fgets(pline, 200, fptr);
			puts(pline);
		if(feof(fptr)) {
			break;
		}
	}
	// free memory and close file
	fclose(fptr);
	free(pline);
	
	return 0;
}
