/*Implement a dynamic array*/
#include "DynArray.h"

int myArraySize  = 0;
int myCurrentIdx = 0;
int *MyArray  = 0;
int *tmpMyArray = 0;
int *tmpSortedArray = 0;


void BubbleSortArray() {
	int i, j, tmpVar;
	if(!tmpSortedArray)
		tmpSortedArray = (int *)malloc(sizeof (int) * (myArraySize));
	
	//copyOriginal Array into tmpSortedArray
	for (i = 0; i < myArraySize; i++)
		tmpSortedArray[i] = MyArray[i];
	
	//implement Bubble sort ascending order
	for (i = 0; i < (myArraySize - 1); i++) {
		for (j = 0; j < (myArraySize - 1); j++) {
			if (tmpSortedArray[j] > tmpSortedArray[i]) {
				tmpVar = tmpSortedArray[j];
				tmpSortedArray[j] = tmpSortedArray[j+1];
				tmpSortedArray[j+1] = tmpVar;
			}
		}
	}
	
	printf("Tmp Sorted Array\t: ");
	for (i = 0; i < myArraySize; i++)
		printf("%d\t", tmpSortedArray[i]);
	
	printf("\n");
}

int BinSearchArrayRecursive(int element, int firstElement, int lastElement) {
	int mid = 0;
	mid = (firstElement + lastElement)/2;
	//printf("Element: %d,  firstElement %d, mid %d, lastElement %d\n", element, firstElement, mid, lastElement);
	if (element == tmpSortedArray[mid]) {
		//printf("FOUND ** %d at %d\n", tmpSortedArray[mid], mid);
		return mid;
	}
	else {
		if (element > tmpSortedArray[mid])
			return BinSearchArrayRecursive(element, (mid + 1), lastElement);		//element is on the right side; return statement is important otherwise the system will still return false on the return from parent function
		else
			return BinSearchArrayRecursive(element, firstElement, (mid - 1));		//element is on the left side
	}
	
	printf("Search failed\n");
	return -1;
}

int BinSearchArrayIterative(int element) {
	int firstElement = 0;
	int mid = 0;
	int lastElement = myArraySize - 1; 				//size of array
	
	while(firstElement <= lastElement) {			//if you don't have the <=, the last element would be missed
		mid = (firstElement + lastElement)/2;		
		if (element == tmpSortedArray[mid])
			return mid;
		else {
			if (element > tmpSortedArray[mid])	//check if element is on left or right side
				firstElement = mid + 1;			//element is on right side of mid
			else {
				lastElement  = mid - 1;   		//element is on the left side of mid
			}
		}
	}
	printf("Search failed\n");
	return -1;
}

int createArray(int sizeofArray) {
	if (sizeofArray < MINSIZEOFARRAY)
		return FALSE;
	
	if(myArraySize == 0) {	// i.e. first time creation
		MyArray = (int *)malloc(sizeof (int) * sizeofArray);
		myArraySize = sizeofArray;
		printf("FIRST TIME CREATION: size of array %d\n", myArraySize);
	}
	else {					//array exists; so append the nodes to the MyArray
		myArraySize +=sizeofArray;
		printf("APPENDED ARRAY SIZE: size of array %d\n", myArraySize);
		tmpMyArray = (int *)malloc(sizeof (int) * (myArraySize));
		for (int i = 0; i < myCurrentIdx; i++) {
			tmpMyArray[i] = MyArray[i];
		}
		free(MyArray);
		MyArray = tmpMyArray;
		//printf("Current Idx %d, Array Size %d", myCurrentIdx, myArraySize); 
	}
	
	return TRUE;
}

void printArray() {
	for (int i=0; i<myCurrentIdx; i++)
		printf("%d\t", MyArray[i]);
	
	printf("\n");
}

int addElement(int element) {
	if ((myCurrentIdx < myArraySize)) {
		MyArray[myCurrentIdx++] = element;
		//printf("Added Element %d at Current Idx %d, Array Size %d\n", element, myCurrentIdx, myArraySize);
		return TRUE;
	}
	return FALSE;
}

int removeElementViaIndex(int Index) {
	int i;
	if (Index > myArraySize) {
		printf("Exception: Invalid Idx");
		return FALSE;
	}
	
	for (i = Index; i < myCurrentIdx;i++)
		MyArray[i] = MyArray[i+1];
	
	myCurrentIdx--;
	//printf("Removed at index %d, new Current Idx %d, Array Size %d\n", Index, myCurrentIdx, myArraySize);
	return TRUE;
}

int main()
{
	createArray(4);

	for (int i = 10; i < 41; i=i+10) {
		if (!addElement(i))
			printf("Exception: Unable to Add Array element\n");
	}
	removeElementViaIndex(2);
	addElement(50);
	printArray();
	
	for (int i = 0; i < myCurrentIdx; i++)	{
		removeElementViaIndex(1);
		printArray();
	}
	createArray(2);
	for (int i = 0; i < 6; i++) {
		if (!addElement(i)) {
			break;
		}
	}
	
	printArray();
	BubbleSortArray();
	printf("Bin Search Iterative solution:\t");
	if (BinSearchArrayIterative(0) != -1)
		printf("Element Exists !!\n");
	
	printf("Bin Search Recursive solution:\t");
	if (BinSearchArrayRecursive(10, 0, myArraySize-1) != -1)
		printf("Element Exists !!\n");
}
