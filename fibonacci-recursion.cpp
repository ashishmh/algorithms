#include <iostream>
#include <cstdio>
using namespace std;

void fibonacci(int a, int b, int n) {
	if ( a == 1 && b == 1 )
		cout<<a<<"\t"<<b<<"\t";
	if( a+b > n )
		return;
	cout<<a+b<<"\t";
	int temp = b;
	b = a+b;
	a = temp;
	fibonacci(a,b,n);
}

int main() {
	freopen("input.txt","r",stdin);

	int n;
	cin>>n;
	fibonacci(1,1,n);
	return 0;
}