//Implement a stack using a queue

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FALSE 0
#define TRUE 1
#define NULL 0

bool isEmpty()
int sizeOfQueue();
int push(int element);
int pop();
void printStackArray();

struct MyQueue {
	int value;
	struct MyQueue *next;
};

struct MyQueue *qHead = NULL;

int empty() {
	return (qHead == NULL) ? TRUE:FALSE;
}

int push(int element) {
	struct MyQueue *qNode = (int *) malloc (size of (MyQueue));
	qNode.value = element;
	qNode.next  = NULL;
	
	if (qHead == NULL) {		//stack is empty
		qHead = qNode;
		return;
	} else {					//insert the node at the right location
		
		
	}
	
}

int pop() {
	if (isEmpty()) {
		printf("stack empty");
		return NULL;
	}
	else {
		//free the head node, and then return the value
		retVal = qHead.value
		qHead->next = (qHead->next)->next;
		free (qHead);
		return retVal;
	}
}

int main() {
	push(10);
	if(retVal = pop() != NULL)
		printf("Pop %d", retVal)
	
	printq();
}
