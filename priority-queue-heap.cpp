// Make a priority queue from a heap and perform its functions (heap-max, heap-extract-max,
// heap-insert-key and heap-max-insert)

#include <iostream>
#include <cstdio>
#include <limits>						// for int limit
using namespace std;

void heapMaxInsert();
void heapIncreaseKey(int* arr, int key, int i);
int heapExtractMax(int* arr, int size);
int heapMaximum(int* arr);
void buildMaxHeap(int* arr, int size);
void heapifyMax(int* arr, int size, int i);
void swap(int* arr, int a, int b);
void printArr(int* arr, int size);

void heapMaxInsert(int* arr, int size, int key) {
	arr[size] = numeric_limits<int>::min();
	heapIncreaseKey(arr, key, size);
	size = size+1;			// here it doesn't make a difference, but heap size should increase after insert
	return;
}

void heapIncreaseKey(int* arr, int key, int i) {
	if (key < arr[i]) {
		cout<<"New key is smaller than old key.."<<endl;
		return;
	}
	arr[i] = key;
	while (i >= 1 && arr[i/2] < arr[i]) {
		swap(arr, i, i/2);
		i = i/2;
	}
	return;
}

int heapExtractMax(int* arr, int size) {
	int max = arr[0];
	arr[0] = arr[size-1];
	size = size-1;
	heapifyMax(arr, size, 0);
	return max;
}

int heapMaximum(int* arr) {
	return arr[0];
}

void buildMaxHeap(int* arr, int size) {
	for (int i=size/2; i>=0; i--)
		heapifyMax(arr, size, i);
	return;
}

void heapifyMax(int* arr, int size, int i) {
	int left = 2*i+1;					// left child
	int right = 2*i+2;					// right child
	int largest = i;
	if (left < size && arr[left] > arr[i])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr, i, largest);
		heapifyMax(arr, size, largest);
	}
	return;
}

void swap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
	return;
}

void printArr(int* arr, int size) {
	for (int i=0; i<size; i++)
		cout<<arr[i]<<" ";
	return;
}

int main() {
    freopen("input.txt","r",stdin);
    
    int arr[50];
    int size;
    cin>>size;
    for (int i=0; i<size; i++)
    	cin>>arr[i];
    cout<<"Original array.. "<<endl;
    printArr(arr, size);
    cout<<endl<<"Max heap of array.. "<<endl;
    buildMaxHeap(arr, size);
    printArr(arr, size);
    cout<<endl<<"Max heap funtion.. "<<endl;
    cout<<heapMaximum(arr);
    cout<<endl<<"Heap increase key function (setting key of arr[5] to 100).. "<<endl;
    heapIncreaseKey(arr, 100, 5);
    printArr(arr, size);
    cout<<endl<<"Heap extract max funtion.. "<<endl;
    cout<<heapExtractMax(arr, size)<<endl;
    printArr(arr, size-1);
    cout<<endl<<"Heap insert key funtion (inserting 999).. "<<endl;
    heapMaxInsert(arr, size-1, 999);
    printArr(arr, size);
    cout<<endl;
    return 0;
}