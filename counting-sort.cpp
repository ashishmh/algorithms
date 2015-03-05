#include <iostream>
#include <cstdio>
using namespace std;

void countingSort(int* A, int n, int k);
void printArr(int* arr, int size);

void countingSort(int* A, int n, int k) {
	// B1 is used for stable and B2 for unstable temp storage
	// C is used as output array
	int B1[k], B2[k], C[n];
	for (int i = 0; i < k; i++)
		B1[i] = B2[i] = 0;
	for (int i = 0; i < n; i++) {
		B1[A[i]] = B1[A[i]] + 1;
		B2[A[i]] = B2[A[i]] + 1;
	}
	// B[i] now contains the number of elements equal to i

	for (int i = 1; i < n; i++) {
		B1[i] = B1[i] + B1[i-1];
		B2[i] = B2[i] + B2[i-1];
	}
	// B[i] now contains the number of elements ≤ i

	// reading A from index n-1 results in stable sort
	for (int i = n-1; i >= 0; i--) {
		C[B1[A[i]]-1] = A[i];
		--B1[A[i]];
	}
	cout<<endl<<"counting sort (stable): ";
	printArr(C, n);

	// reading A from index 0 results in unstable sort
	for (int i = 0; i < n; i++) {
		C[B2[A[i]]-1] = A[i];
		--B2[A[i]];
	}
	cout<<endl<<"counting sort (unstable): ";
	printArr(C, n);
}

void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
    freopen("input.txt","r",stdin);

	int n, k;					// n is no of elements, and k is max value of any element
	cin>>n>>k;
	int A[n];
	for (int i = 0; i < n; i++)
		cin>>A[i];
	cout<<"original array: ";
	printArr(A, n);
	countingSort(A, n, k);
	cout<<endl;
	return 0;
}