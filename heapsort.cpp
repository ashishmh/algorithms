// Perform heapsort on input array

#include <iostream>
#include <cstdio>
using namespace std;

void heapifyMax(int* arr, int, int);
void swap(int* arr, int, int);
void buildMaxHeap(int*, int);

void heapSort(int* arr, int size) {
	int array_length, heap_size;
	array_length = heap_size = size;
	buildMaxHeap(arr, heap_size);
	for (int i=array_length-1; i>0; i--) {
		swap(arr, 0, i);
		heap_size = heap_size-1;
		heapifyMax(arr, heap_size, 0);
	}
	return;
}

void buildMaxHeap(int* arr, int size) {
	for (int i=size/2-1; i>=0; i--)
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
    
    int size;
    cin>>size;
    int arr[size];
    for (int i=0; i<size; i++)
    	cin>>arr[i];
    cout<<"original array.. "<<endl;
    printArr(arr, size);
    heapSort(arr, size);
    cout<<endl<<endl<<"sorted array.."<<endl;
    printArr(arr, size);
    cout<<endl;
    return 0;
}