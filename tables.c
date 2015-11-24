#include <stdio.h>

#define NUM 2

int main() {
	int multi = 1, ans;
	
	while(multi <= 10) {
		ans = NUM * multi;
		printf("%d x %d = %d \n", NUM, multi, ans);
		multi++;
		ans = 0;
	}
	return 0;
}
