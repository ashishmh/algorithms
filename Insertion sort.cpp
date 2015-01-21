/* In insertion sort, we take each element in the list one by one and insert it into its
correct position in the sorted list (which is initially empty) */

#include <iostream>
#include <cstdio>
using namespace std;

void insertionSort(int* arr, int size) {
	for(int i=1; i<size; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] < arr[j]) {
                int temp = arr[i];
                for(int k=i-1; k>=j; k--)
                    arr[k+1] = arr[k];
                arr[j] = temp;
            }
        }
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
    cout<<"Insertion sort:"<<endl;
    insertionSort(arr, size);
    printArr(arr, size);
    return 0;
}