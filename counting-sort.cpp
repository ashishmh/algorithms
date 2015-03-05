#include <iostream>
#include <cstdio>
using namespace std;

void countingSort(int* A, int n, int k);
void printArr(int* arr, int size);

void countingSort(int* A, int n, int k) {
	int B[k], C[n];
	for (int i = 0; i < k; i++)
		B[i] = 0;
	for (int i = 0; i < n; i++)
		B[A[i]] = B[A[i]] + 1;
	// B[i] now contains the number of elements equal to i

	for (int i = 1; i < n; i++)
		B[i] = B[i] + B[i-1];
	// B[i] now contains the number of elements ≤ i

	for (int i = 0; i < n; i++) {
		C[B[A[i]]-1] = A[i];
		--B[A[i]];
	}
	cout<<endl<<"counting sort: ";
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