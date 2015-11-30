#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
   insertnode = inserting node.
   printnode = printing our linked list.
   deletenode = deleting node at any given pos
		entered by user
 */
void insertnode(int val, int pos);
void printnode();
void deletenode();

struct node {
	int data;
	struct node* next;
};

// Head/Start of our Linked List.
struct node* head = NULL;

int main(void) {

	int val, len, pos;
	printf("How Many elements you want in your Linked list? \n");
	scanf(" %d", &len);

	//Make randomisation independent of fixed system seed
	srand(time(NULL));
	for(int i=1; i<=len; i++) {
		val = rand() % 10;
		insertnode(val, i);
		printf("your list is : ");
		printnode();
	}

	puts("Enter Your Desired Position to delete");
	scanf(" %d", &pos);
	deletenode(pos);
	printf("\nyour list is  now : ");
	printnode();

	return 0;
}

void insertnode(int val, int pos) {

	struct node* tmp = (struct node *)malloc(sizeof(struct node));
	tmp->data = val;
	tmp->next = NULL;
	if(pos == 1) {
		tmp->next = head;
		head = tmp;
		return;
	}
	struct node* tmp2 = head;
	for(int i=0; i<pos-2; i++) {
		tmp2 = tmp2->next;
	}
	tmp->next = tmp2->next;
	tmp2->next = tmp;
}

void printnode() {
	struct node* tmp = head;
	while(tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	puts(" ");
}

void deletenode(int pos) {
	struct node* tmp = head;
	if(pos == 1) {
		head=tmp->next;
		free(tmp);
		return;
	}
	for(int i=0; i<pos-2; i++) {
		tmp = tmp->next;
	}
	struct node* tmp2 = tmp->next;
	tmp->next = tmp2->next;
	free(tmp2);
}
