#include <stdio.h>
#include <stdlib.h>

struct stack* push(int val, struct stack* ptrTop);
struct stack* pop(struct stack* ptrTop);
void get_top_val(struct stack* ptrTop);
void print_stack(struct stack* ptrTop);
void print_top(int val);
int isEmpty(struct stack* ptrTop);


struct stack {
	int data;
	struct stack* next;
};

int main() {
	struct stack *top = NULL;
	top = push(rand() % 10, top);
	print_stack(top);
	top = pop(top);
	print_stack(top);
	top = pop(top);
	print_stack(top);
	top = push(rand() % 10, top);
	print_stack(top);
	top = push(rand() % 10, top);
	print_stack(top);
	top = push(rand() % 10, top);
	print_stack(top);
	top = push(rand() % 10, top);
	print_stack(top);
	top = push(rand() % 10, top);
	print_stack(top);
	top = push(rand() % 10, top);
	print_stack(top);
	top = push(rand() % 10, top);
	print_stack(top);
	get_top_val(top);
	top = pop(top);
	print_stack(top);
}

struct stack* push(int val, struct stack* ptrTop) {
	struct stack* temp = (struct stack *)malloc(sizeof(struct stack));
	temp->data = val;
	temp->next = ptrTop;
	ptrTop = temp;
	return ptrTop;
}

struct stack* pop(struct stack* ptrTop) {
	if(isEmpty(ptrTop) == 0) {
		printf("Error: no elements in stack to pop, Stack is Empty \n");
		return ptrTop;
	}
	struct stack* temp = ptrTop;
	ptrTop = temp->next;
	free(temp);
	return ptrTop;
}

void get_top_val(struct stack* ptrTop) {
	print_top(ptrTop->data);
}

void print_top(int val) {
	printf("Your Value at TOP is : %d \n", val);
}

int isEmpty(struct stack* ptrTop) {
	return (ptrTop == NULL) ? 0 : 1;
}

void print_stack(struct stack* ptrTop) {
	if(isEmpty(ptrTop) == 0) {
		printf("Error: no elements in stack to display, Stack is Empty \n");
		return;
	}
	printf("Your Stack is : ");
	while(ptrTop != NULL) {
		printf("%d ", ptrTop->data);
		ptrTop = ptrTop->next;
	}
	puts(" ");
}

