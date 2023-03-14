/*Implement bubble sort; and binary search;; stack ds with push pop and peek methods*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int myArraySize = 0;
int myCurrentIdx = 0;
int MyArray[10];
int *tmpMyArray;
#define TRUE 1
#define FALSE 0
#define MINSIZEOFARRAY 1

bool isArrayFull() {
	return (myCurrentIdx == sizeof(MyArray)/sizeof(MyArray[0]) ? TRUE : FALSE);
}

bool isArrayEmpty() {
	return (myCurrentIdx == 0) ? TRUE : FALSE;
}

void InsertAtIndex(int idx, int element) {
	int i = 0;
	if(!isArrayFull()) {
		//is it an invalid index
		if(idx > myCurrentIdx) {
			printf("Inserting at Invalid Index\n");
			return;
		}
			
		for (i = (myCurrentIdx-1); i >= idx; i--) {
			MyArray[i+1] = MyArray[i];
			//printf("Shifting to idx %d, Element %d from Idx %d, Element %d\n", i+1, MyArray[i+1], i, MyArray[i]);
		}
		
		MyArray[idx] = element;
		myCurrentIdx++;
	}
	else
		printf("arr: Full\n");
}

void RemoveFromIndex(int index) {
	if(!isArrayEmpty()) {
		if(index > myCurrentIdx) {
			printf("Invalid Idx\n");
			return;
		}
		
		for (int i = index; i < myCurrentIdx; i++) {
			MyArray[i] = MyArray[i+1];
		}
		myCurrentIdx--;
	}
	else
		printf("arr: Empty\n");
}

void printArray() {
	
	printf("MyArraySize: %d:\t", myCurrentIdx);
	for (int i=0; i<myCurrentIdx; i++)
		printf("%d\t", MyArray[i]);
	
	printf("\n", myCurrentIdx);
}

void myBubbleSortArray() {
	int tmpVar;
	for (int i = 0; i < (myCurrentIdx-1); i++) {
		for (int j = 0; j < (myCurrentIdx - i - 1); j++) {
			if (MyArray[j] > MyArray[j+1]) {
				tmpVar = MyArray[j];
				MyArray[j] = MyArray[j+1];
				MyArray[j+1] = tmpVar;
			}
		}
	}
}

int main()
{
	int j = 0, idx = -1;
	for (int i = 8; i > 0; i--) {
		MyArray[i] = j * 10;
		myCurrentIdx++; j++;
	}	
	printArray();
	InsertAtIndex(3, 999);
	printArray();
	for(int i = 0; i < 9; i++) {
		RemoveFromIndex(1);
		printArray();
	}
	RemoveFromIndex(0);
	
	InsertAtIndex(3, 999);
	printArray();
	
	for (int i = 1; i < 9; i++) {
		MyArray[i-1] = ((9-j++) * 10);
		myCurrentIdx++;
	}
	printArray();
	myBubbleSortArray();
	printArray();
}
