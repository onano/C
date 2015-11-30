#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int i, j;
	
	for(i=0; i<=5; i++) {
		for(j=0; j<=5; j++) {
			printf("%d", i);
		}
		printf("\n");
	}
	return 0;
}
