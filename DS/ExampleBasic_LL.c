/*
 * It's a program to demonstrate Common
 * Single LInked List Functions.
 */

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0

/**
 * insertnode = is a logic to insert node into our given Linked List.
 * deletenode = deleting a particular node via its position
 * getNewNode = a simple node generater logic
 * reverse_list = reversing out Linked List.
 * printnode = simple printing of node.
 * printnode_reverse = to see your list in reverse order without actually reversing it.
 *
 **/
struct node* insertnode(int val, int pos, struct node* ptrHead);
struct node* deletenode(int pos, struct node *ptrHead);
struct node* reverse_list(struct node *ptrHead);
struct node* getNewNode(int val);
void printnode(struct node* ptrHead);
void printnode_reverse(struct node *ptrHead);

/*
 * Nodes For Linked List
 */
struct node {
	int data;
	struct node* next;
};

/*
 * head = ptr to head/starting node for our Linked List.
 * val = value to insert in our list->data
 * len = how much bigger we want our List
 * usrEnt = Selection storing for input by users
 * pos = postition for linked list.
 */
int main() {
	struct node *head = NULL;
	int val, len, usrEnt, pos;
	printf("Enter How Many elements you want in Your Linked List. \n");
	scanf(" %d", &len);

	puts("Generating Your Linked List ...");
	for(pos=1; pos<=len; pos++) {
		val = rand() % 10; //we want to keep value between 0-9
		head = insertnode(val, pos, head);
	}
	printnode(head); //print it before any further prompts

	//Lets Ask User What he Wants to do.
	puts("What You want to Do with Your list?");
	puts("Press 1 to Delete a node");
	puts("Press 2 to Reverse This List");
	puts("Press 3 to see your list in reverse order (without reversing it)");
	puts("Press 4 to exit.");
	scanf(" %d", &usrEnt);

	pos = 0;
	if(usrEnt == 1) {
		puts("Please Enter Position You want to delete.");
		scanf(" %d", &pos);
		head = deletenode(pos, head);
		printnode(head);
		return SUCCESS;
	}
	else if(usrEnt == 2) {
		puts("Reversing your List...");
		head = reverse_list(head);
		printnode(head);
		return SUCCESS;
	}
	else if(usrEnt == 3){
		printf("Your List is : ");
		printnode_reverse(head);
		return SUCCESS;
	}
	else {
		return SUCCESS;
	}
}

struct node* insertnode(int val, int pos, struct node *ptrHead) {
	struct node *temp = getNewNode(val);
	if(pos == 1) {
		temp->next = ptrHead;
		ptrHead = temp;
		return ptrHead;
	}
	//Create a new refernce to head so, we can treverse.
	struct node* temp2 = ptrHead;
	for(int i=0; i<pos-2; i++) {
		temp2 = temp2->next;
	}
	temp->next = temp2->next;
	temp2->next = temp;
	return ptrHead;
}

struct node* deletenode(int pos, struct node *ptrHead) {
	struct node* temp = ptrHead;
	if(pos == 1) {
		ptrHead = temp->next;
		free(temp);
		return ptrHead;
	}
	for(int i=0; i<pos-2; i++) {
		temp = temp->next;
	}
	struct node* temp2 = temp->next;
	temp->next = temp2->next;
	free(temp2);
	return ptrHead;
}

struct node* reverse_list(struct node *ptrHead) {
	struct node *prev, *current, *next;
	prev = NULL;
	current = ptrHead;
	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	ptrHead = prev;
	return ptrHead;
}

struct node* getNewNode(int val) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

void printnode(struct node *ptrHead) {
	printf("Your List is : ");
	while(ptrHead != NULL) {
		printf("%d ", ptrHead->data);
		ptrHead = ptrHead->next;
	}
	printf("\n");
}

void printnode_reverse(struct node *ptrHead) {
	if(ptrHead == NULL) {
		return;
	}
	printnode_reverse(ptrHead->next);
	printf("%d ", ptrHead->data);
}

