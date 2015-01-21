/* Merge-sort is based on the divide-and-conquer paradigm. It involves the following three steps:
Divide the array into two (or more) subarrays
Sort each subarray (Conquer)
Merge them into one (in a smart way!) */

#include <iostream>
#include <cstdio>
using namespace std;

void merge(int*, int, int, int);

void mergeSort(int* arr, int beg, int end) {
	if (beg < end) {
		int mid = (beg+end)/2;
		mergeSort(arr, beg, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, beg, end, mid);
	}
	return;
}

void merge(int* arr, int beg, int end, int mid) {
	int temp[50], i, j, k;
	i = beg; j = mid+1; k = beg;
	while (i <= mid && j <= end)
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= end)
		temp[k++] = arr[j++];
	for (i=0; i <= end; i++)
		arr[i] = temp[i];
	return;
}

void printArr(int* arr, int size) {
    for (int i=0; i < size; i++)
        cout<<arr[i]<<endl;
    return;
}

int main() {
    freopen("input.txt","r",stdin);

    int size;
    cin>>size;
    int arr[size];
    for (int i=0; i < size; i++)
    	cin>>arr[i];
    cout<<"Merge sort:"<<endl;
    mergeSort(arr, 0, size-1);
    printArr(arr, size);
    return 0;
}