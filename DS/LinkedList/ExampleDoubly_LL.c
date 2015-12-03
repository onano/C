#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node* insertnode(int val, int pos, struct node *ptrHead);
struct node* getNewNode(int val);
struct node* set_tail(struct node *ptrHead);
void printnode(struct node *ptrHead);
void printnode_reverse(struct node *ptrHead);
void print_tail(struct node *ptrTail);

struct node {
	int data;
	struct node* prev;
	struct node* next;
};

int main() {
	int val, len;
	struct node *head = NULL, *tail = NULL;
	puts("How Many Elements You Want in your Linked List");
	scanf(" %d", &len);
	//Let's Make Random independent of fixed system seed.
	srand(time(NULL));
	for(int i=1; i<=len; i++) {
		val = rand() % 10; //Keep it B/W :: 0-9
		head = insertnode(val, i, head);
		/* reset tail  */
		tail = set_tail(head);
	}

	//Lets print lists
	printnode(head);
	printnode_reverse(tail);
	/* check if our tail logic working right */
	print_tail(tail);
}

struct node* insertnode(int val, int pos, struct node *ptrHead) {
	struct node *temp = getNewNode(val);
	if(pos == 1) {
		if(ptrHead == NULL) {
			ptrHead = temp;
			return ptrHead;
		} else {
			/*
			 * if ptrHead is not null set prev and next accordingly
			 */
			temp->next = ptrHead->next;
			temp->prev = ptrHead;
			ptrHead = temp;
			return ptrHead;
		}
	}
	struct node *temp2 = ptrHead;
	for(int i=0; i<pos-2; i++) {
		temp2 = temp2->next;
	}
	temp->next = temp2->next;
	temp->prev = temp2;
	temp2->next = temp;
	return ptrHead;
}

struct node* set_tail(struct node *ptrHead) {
	struct node *ptrTail = ptrHead;
	while(ptrHead->next != NULL) {
		ptrHead = ptrHead->next;
	}
	ptrTail = ptrHead;
	return ptrTail;
}

/* debug method to see if my tail implementation working */
void print_tail(struct node *ptrTail) {
	printf("Your tail data is  : %d \n" , ptrTail->data);
}

struct node* getNewNode(int val) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void printnode(struct node *ptrHead) {
	printf("Your List in Straight order is  : ");
	while(ptrHead != NULL) {
		printf("%d ", ptrHead->data);
		ptrHead = ptrHead->next;
	}
	puts(" ");
}

void printnode_reverse(struct node *ptrTail) {
	printf("Your List in Reverse order is  : ");
	struct node *temp = ptrTail;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	puts(" ");
}
