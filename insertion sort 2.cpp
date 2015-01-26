#include <iostream>
#include <cstdio>
using namespace std;

void insertionSort(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		for (int j = i-1; j >= 0 && arr[j] > key; j--) {
			arr[j+1] = arr[j];
			arr[j] = key;
		}
	}
	return;
}

void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++)
		cout<<arr[i]<<endl;
	return;
}

int main() {
    freopen("input.txt","r",stdin);

    int size;
    cin>>size;
    int arr[size];
    for (int i = 0; i < size; i++)
    	cin>>arr[i];
    insertionSort(arr, size);
    printArr(arr, size);
    return 0;
}