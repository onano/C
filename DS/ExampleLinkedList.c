#include <stdio.h>
#include <stdlib.h>
/*
 * To insert our node
 */
void insertnode(int val, int n_pos);

/*
 * To display our linked list.
 */
void printnode();

/*
 * To Sort our list data cause why the heck not?
 */
void sort();

struct node {
	int data;
	struct node* next;
};

/*
 * variable for our node head.
 */
struct node* head = NULL;

int main(void) {

	int len, val;

	puts("How much Big You want your Linked List ?");
	scanf(" %d", &len);

	puts("Enter Your Elements :");
	for(int i=1; i<=len; i++) {
		scanf(" %d", &val);
		insertnode(val, i);
		printnode();
	}
	return 0;
}

void insertnode(int val, int n_pos) {
	struct node* tmp = (struct node *)malloc(sizeof(struct node));
	tmp->data = val;
	tmp->next = NULL;
	if(n_pos == 1) {
		tmp->next = head;
		head = tmp;
		return;
	}
	struct node* tmp2 = head;
	for(int i=0; i<n_pos-2; i++) {
		tmp2 = tmp2->next;
	}
	tmp->next = tmp2->next;
	tmp2->next = tmp;
}

void printnode() {
	struct node* tmp = head;
	puts("Your List is : ");
	while(tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
