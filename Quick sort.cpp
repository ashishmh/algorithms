/* Quicksort is a divide and conquer algorithm. Quicksort first divides a large array into two
smaller sub-arrays: the low elements and the high elements. Quicksort can then recursively sort
the sub-arrays.

The steps are:
1. Pick an element, called a pivot, from the array.
2. Reorder the array so that all elements with values less than the pivot come before the pivot,
while all elements with values greater than the pivot come after it (equal values can go either
way). After this partitioning, the pivot is in its final position. This is called the partition operation.
3. Recursively apply the above steps to the sub-arrays around the pivot.

The base case of the recursion is arrays of size zero or one, which never need to be sorted. */

#include <iostream>
#include <cstdio>
using namespace std;

int partition(int*, int, int);
void swap(int*, int, int);
void printArr(int*, int);

void quickSort(int* arr, int lo, int hi) {
	if (lo < hi) {
		int p = partition(arr, lo, hi);
		quickSort(arr, lo, p-1);
		quickSort(arr, p+1, hi);
	}
	return;
}

int partition(int* arr, int lo, int hi) {
	int pivotIndex = lo, pivotValue = arr[pivotIndex];
	int storeIndex = lo;
	swap(arr, pivotIndex, hi);
	for (int i=lo; i<hi; i++)
		if (arr[i] < pivotValue) {
			swap(arr, i, storeIndex);
			++storeIndex;
		}
	swap(arr, storeIndex, hi);
	return storeIndex;
}

void swap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
	return;
}

void printArr(int* arr, int size) {
    for(int i=0; i<size; i++)
        cout<<arr[i]<<endl;
    return;
}

int main() {
    freopen("input.txt","r",stdin);

    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++)
    	cin>>arr[i];
    cout<<"Quick sort:"<<endl;
    quickSort(arr, 0, size-1);
    printArr(arr, size);
    return 0;
}