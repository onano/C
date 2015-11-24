#include <stdio.h>
#include <stdlib.h>

#define LOOP 1

int main() {
	char file[300];
	FILE *fptr;
	fptr = fopen("/home/mohit/Desktop/c-programs/myfile.txt", "r");
	while(LOOP) {
		if(fgets(file, 300, fptr) != NULL) {
			puts(file);
		}
		if(feof(fptr)) {
				break;
		}
	}
	fclose(fptr);
	return 0;
}
