/*
 * Simple program to help 
 * understand gets and puts
 */
 
 #include <stdio.h>
 #include <ctype.h>
 #include <stdlib.h>
 #include <string.h>
 
 int main() {
	 
	 char catname[20], catfood[20], final[50] ="";
	 
	 puts("Enter your cat name?");
	 gets(catname);
	 
	 puts("What does your cat eat?");
	 gets(catfood);
	 
	 strcat(final, catname);
	 strcat(final, " likes to eat ");
	 strcat(final, catfood);
	 
	 puts(final);
	 
	 return 0;
 }
