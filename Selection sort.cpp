#include <iostream>
#include <cstdio>
using namespace std;

void selectionSort(int* arr, int size) {
	int first = 0;
    while(first < size) {
        int smallest = first;
        for(int i=first+1; i<size; i++) {
            if(arr[smallest] > arr[i])
                smallest = i;
        }
        int temp = arr[first];
        arr[first] = arr[smallest];
        arr[smallest] = temp;
        ++first;
    }
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
    cout<<"Selection sort: "<<endl;
    selectionSort(arr, size);
    printArr(arr, size);
    return 0;
}