#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0

int main() {
	
	FILE *fptr = NULL;
	fptr = fopen("myfile.txt", "w");
	fprintf(fptr, "hello you awsome c made files");
	fclose(fptr);
	
	return SUCCESS;
}
