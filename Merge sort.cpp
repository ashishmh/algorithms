/* Merge-sort is based on the divide-and-conquer paradigm. It involves the following three steps:
Divide the array into two (or more) subarrays
Sort each subarray (Conquer)
Merge them into one (in a smart way!) */

#include <iostream>
#include <cstdio>
using namespace std;

void mergeSort(int* arr, int beg, int end);
void merge(int*, int, int, int);
void printArr(int* arr, int size);
void printArray(int* arr, int beg, int end);

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
  int temp[end+1], i, j, k;
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
  for (i = beg; i <= end; i++)
    arr[i] = temp[i];
  return;
}

void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    return;
}

int main() {
    int arr[] = {1, 5, 20, 6, 4, 5, 56};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArr(arr, n);
    cout<<endl;

    cout<<"Merge sort: ";
    mergeSort(arr, 0, n-1);
    printArr(arr, n);

    cout<<endl<<endl;
    return 0;
}