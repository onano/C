#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node* insertnode(int val, int pos, struct node* head);
struct node* reverse_list(struct node* head);

void printnode(struct node* head);

struct node {
	int data;
	struct node* next;
};

int main(void) {
	struct node* head = NULL;
	int len, val;
	puts("How much elements you want in your list.");
	scanf(" %d", &len);

	//Make Random indepent of fixed system seed
	srand(time(NULL));

	// Create the List.
	for(int i=1; i<=len; i++) {
		val = rand() % 10;
		head = insertnode(val, i, head);
	}

	//Print list before reversing
	printnode(head);

	int userEnt;
	puts("Do you want to reverse it? [1 for yes/ 0 for no]");
	scanf(" %d", &userEnt);
	if(userEnt == 1) {
		//reverse the list
		head = reverse_list(head);
		//Print list after reversing
		printnode(head);
	}

	return 0;
}

struct node* insertnode(int val, int pos, struct node* head) {
	//creating a node
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->next = NULL;
	if(pos == 1) {
		temp->next = head;
		head = temp;
		return head;
	}
	struct node* temp2 = head;
	for(int i=0; i<pos-2; i++) {
		temp2 = temp2->next;
	}
	temp->next = temp2->next;
	temp2->next = temp;
	return head;
}

void printnode(struct node* head) {
	struct node* temp = head;
	printf("Your List is now : ");
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

struct node* reverse_list(struct node* head) {
		struct node *prev, *current, *next;
		prev = NULL;
		current = head;
		while(current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current =  next;
		}
		head = prev;
		return head;
}

