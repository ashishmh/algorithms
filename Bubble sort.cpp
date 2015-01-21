/* In bubble sort, in the first pass we bubble across the largest element to the last position,
in the 2nd pass, the 2nd largest element to the 2nd last position and so on until a pass
occurs where there was no swap made. We bubble across elements by comparing adjacent elements
starting from the first two */

#include <iostream>
#include <cstdio>
using namespace std;

void bubbleSort(int* arr, int size) {
	bool flag = true;
    while(flag) {
        flag = false;
        for(int i=0; i<size; i++) {
            if(arr[i] > arr[i+1]) {
                flag = true;
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
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
    cout<<"Bubble sort:"<<endl;
    bubbleSort(arr, size);
    printArr(arr, size);
    return 0;
}