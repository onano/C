/*
 * It's a password checker 
 * where user enters a passwd and
 * we check if it is a Strong passwd or nah
 * criteria for strong passwd
 * 1.  MUST contain a uuper case letter
 * 2.  a lower case letter 
 * 3. a symbol 
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 
 int main() {
	 
	 char upasswd[30];
	 int flag = 0, low = 0, __DEBUG__ = 1;
	 
	 printf("Enter a password you want to check \n");
	 scanf("%s", upasswd);
	 
	 for(int i=0; upasswd[i]!='\0'; i++) {
		 if(isalpha(upasswd[i])) {
			 if(isupper(upasswd[i])) {
				flag++;
				if(__DEBUG__ == 1)
					printf("\nFlag Alpha upper value is : %d \t", flag);
			 }
			 if(islower(upasswd[i])) {
				low++; 
				if(__DEBUG__ == 1)
					printf("\nFlag Alpha Low value is : %d \t", low);
			 }
		 }
		 if(isdigit(upasswd[i])) {
			 flag++;
			 if(__DEBUG__ == 1)
				printf("\nFlag digit value is : %d \t", flag);
		 } 
		 if(ispunct(upasswd[i])) {
			 flag++;
			 if(__DEBUG__ == 1)
				printf("\nFlag punct value is : %d \t", flag);
		 }
	 }
	 
	 if(flag >= 3 && low >= 1) {
		 printf("\nYou've made a nice passwd");
	 }
	 else {
		 printf("\n You've made a CRAP passwd");
	 }
	 
	 return 0;
 }

