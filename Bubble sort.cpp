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