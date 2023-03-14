//Implement a stack in an array; methods to implement, push, pop and peek and getMin in O(1) completxity (space and time)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int stackArray[5];
int arraySize = -1;
#define FALSE 0
#define TRUE 1
void printStackArray();

int isEmpty() {
	return (arraySize == 0) ? TRUE : FALSE;
}

int isFull() {
	return  (arraySize == sizeof(stackArray)/sizeof(int)) ? TRUE : FALSE;
}

int push(int element) {
	//check if stack is full already or not1
	if(isFull()) {
		printf("stack full\n");
		return FALSE;
	}

	if(isEmpty()) { //push the element at top;
		stackArray[arraySize++] = element;
		//printStackArray();
		return TRUE;
	} 
	else {		//step 1: find correct index for the element to be inserted where the lowest will be at top; step 2: move elements on the right to further right
		int index = -1;
		for (int i = 0; i <= arraySize; i++) {
			if (stackArray[i] > element) {			//linear search to find the index where element should be inserted
				index = i;
				break;
			}
		}
		if(index == -1)				//indicates element should inserted at the end
			index = arraySize;
		
		//printf("Element %d to be insert at index %d, and arraySize %d\n", element, index, arraySize);
		for (int i = arraySize; i >= index; i--) {
			stackArray[i+1] = stackArray[i];		//move elements from index+1 to the stack's right
		}
		
		arraySize++;
		stackArray[index] = element;
		//printStackArray();
		//printf("\n\n");
		return TRUE;
	}
}

int pop() {
	if(!isEmpty()) {
		int retVal = stackArray[0];
		for(int i = 0; i < (arraySize); i++) {
			stackArray[i] = stackArray[i+1];
		}
		stackArray[arraySize--] = -1;			//reset to initial value
		
		return retVal;
	}
	printf("stack empty\n");
	return -1;
}

void printStackArray() {
	for (int i = 0; i < arraySize; i++)
		printf("%d,\t", stackArray[i]);
	
	printf("SA: %d\n", arraySize);
}

void initStackArray() {
	arraySize++;
	for (int i = 0; i < sizeof(stackArray)/sizeof(int); i++)
		stackArray[i] = -1;
	
	return;
}

int main() {
	int popRetVal;
	initStackArray();
	srand(time(0));
	for (int i = 0; i < 7; i++)
	{
		
		int rndVal = rand() % 5;
		printf("Push = %d, ", rndVal );
		push(rndVal);
	}	
	printStackArray();
	/*
	push(1);		//push element in the right location of array
	push(2);		//push element in the right location of array
	push(4);		//push element in the right location of array
	push(0);		//push element in the right location of array
	push(4);		//push element in the right location of array
	push(3);		//push element in the center location when array is full
	*/
	for (int i = 0; i< 7; i++) {
		popRetVal=pop();
		if( popRetVal != -1) 
			printf("Pop: %d\n",popRetVal);
	}
	printStackArray();
}
