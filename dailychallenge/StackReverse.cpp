/* Reverse a stack without using extra space in O(n)
Ex: Input == 1, 2, 3, 4
Outpit    = 4, 3, 2, 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FALSE 0
#define TRUE 1
int sizeofList = 0;

struct MyNode {
	int value;
	struct MyNode *next;
};

struct MyNode *Hptr, *TailPtr;

bool isEmpty() {
	return (Hptr == NULL) ? TRUE : FALSE;
}

void copyList() {
	struct MyNode tmpNode;
	struct *TraversePtr = Hptr;
	struct *EndPtr = Hptr;
	struct *ReverseListPtr = (struct MyNode*) malloc (sizeof(struct MyNode));
	
	if(isEmpty)
		return;
	
	while(TraversePtr != NULL) {
		ReverseListPtr->value = TraversePtr->value;
		TraversePtr = TraversePtr->next;
	}
	
	
}

void push(int element) {
	struct MyNode *ptr = (struct MyNode*) malloc (sizeof(struct MyNode));
	ptr->value = element;
	ptr->next = NULL;
	ptr->next = Hptr; 
	Hptr = ptr;
	sizeofList++;
}

void printList()
{
	struct MyNode *printptr = Hptr;
	while(printptr != NULL) {
		printf("%d, \t", printptr->value);
		printptr = printptr->next;
	}
	printf("\n");
}

int main()
{
	//create a list
	push(1);
	push(2);
	push(3);
	push(4);
	printList();
	//reverseList();
	//printList();
}
