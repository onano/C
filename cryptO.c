/*
 * cryptO.c
 * 
 * Copyright 2016 Mohit <mohit.srivastava@protonmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

static int get_matrix(void);

struct data {
	char deString[30];
};

int main(int argc, char **argv)
{	
	int err;
	
	err = get_matrix();
	if (err) {
		printf("%s : error in setting intial matrix \n", __func__);
	}
		
	return 0;
}

int check_deString(char *upasswd) {
	
	int flag = 0, low = 0;
	
	for(int i=0; upasswd[i]!='\0'; i++) {
		 if(isalpha(upasswd[i])) {
			 if(isupper(upasswd[i])) {
				flag++;
			 }
			 
			 if(islower(upasswd[i])) {
				low++; 
			 }
		 }
		 
		 if(isdigit(upasswd[i])) {
			 flag++;
		 }
		 
		 if(ispunct(upasswd[i])) {
			 flag++;
		 }
	 }
	 
	 if(flag >= 3 && low >= 1)
		 return 0;
	 else
		 return 1;
}

//while(true)

int set_matrix(char *upasswd) {
		char matrix[50][50];
		int i = 0, flag = 0;
		//printf("The string is : %s \n", upasswd);
		while(upasswd[i]!='\0') {
			for(int j=0; j<50; j++) {
				if(j == i)
					matrix[i][j] = upasswd[i];
				else
					matrix[i][j] = 'x';
			}
			flag++;
			i++;
		}
		
		for(int x=0; x<50; x++) {
			for(int y=0; y<50; y++) {
				printf("%c", matrix[x][y]);
			}
			printf("\n");
		}
		return 0;
}

static int get_matrix(void) 
{
	struct data *d = (struct data *)malloc(sizeof(struct data));
	int err;

	printf("Please enter your desired string \n");
	scanf("%s", d->deString);
	
	err = check_deString(d->deString);
	printf("The string is : %s \n", d->deString);
	if (err) {
		printf("%s : string syntax \n", __func__);
		return 1;
	}
	
	err = set_matrix(d->deString);
	if (err) {
		printf("%s : matrix \n", __func__);
		return 1;
	}
	
	return 0;
}


