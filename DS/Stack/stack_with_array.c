/* stack using arrays */
#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
int isEmpty();
void get_top();
void print_stack();

#define MAX_SIZE 50

int arr[MAX_SIZE];
int top = -1;

int main() {

	push(rand() % 10);
	pop();
	pop();
	push(rand() % 10);
	print_stack();
	push(rand() % 10);
	print_stack();
	push(rand() % 10);
	print_stack();
	push(rand() % 10);
	get_top();
	push(rand() % 10);
	print_stack();
	pop();
	pop();
	print_stack();
	push(rand() % 10);
	print_stack();
	get_top();
}

void push(int val) {
	if(top == MAX_SIZE -1) {
		printf("Error: Stack Overflow.. \n");
		return;
	}
	arr[++top] = val;
}

void pop() {
	if(isEmpty() == 0) {
		puts("Error: no elements in stack to pop, Stack is Empty");
		return;
	}
	arr[top] = 0;
	top--;
}

int isEmpty() {
	return (top == -1) ? 0 : 1;
}

void get_top() {
	printf("Value at TOP is = %d \n", arr[top]);
}

void print_stack() {
	printf("Your Stack is : ");
	for(int i=0; i<=top; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

