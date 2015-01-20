/* Linear search and Binary search (using iteration and recursion) */

#include <iostream>
#include <cstdio>
using namespace std;

void lsearch(int* arr, int size, int x) {
    if(arr) {
        cout<<"Linear Search: ";
        for(int i=0; i<size; i++) {
            if(arr[i] == x) {
                cout<<"Element found "<<x<<endl;
                return;
            }
        }
        cout<<"Element not found "<<x<<endl;
    }
    return;
}

void bsearch(int* arr, int size, int x) {
    if(arr) {
        cout<<"Binary Search: ";
        int beg = 0, end = size-1, mid = (beg+end)/2;
        while(beg < end) {
            if(x == arr[mid]) {
                cout<<"Element found "<<x<<endl;
                return;
            }
            else if(x > arr[mid]) {
                beg = mid+1;
                mid = (beg+end)/2;
            }
            else {
                end = mid-1;
                mid = (beg+end)/2;   
            }
        }
        cout<<"Element not found "<<x<<endl;
    }
    return;
}

void bsearchRecursion(int* arr, int beg, int end, int x) {
    if(arr) {
        if(beg > end) {
            cout<<"Element not found "<<x<<endl;
            return;
        }
        int mid = (beg+end)/2;
        if(x == arr[mid]) {
            cout<<"Element found "<<x<<endl;
            return;
        }
        else if(x > arr[mid])
            bsearchRecursion(arr, mid+1, end, x);
        else bsearchRecursion(arr, beg, mid-1, x);
    }
}

int main() {
    freopen("input.txt","r",stdin);

    int arr[10], size = 10;
    for(int i=0; i<size; i++)
        cin>>arr[i];
    lsearch(arr, size, 2);
    lsearch(arr, size, 11);
    bsearch(arr, size, 3);
    bsearch(arr, size, 12);
    cout<<"Binary Search using Recursion: "<<endl;
    bsearchRecursion(arr, 0, 9, 4);
    bsearchRecursion(arr, 0, 9, 13);
    return 0;
}