#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);

	int i,j,n;
	cin>>n;
	i = j = 1;
	cout<<"0\t"<<i<<"\t"<<j<<"\t";
	while( i+j < n ) {
		int temp = j;
		j = i+j;
		i = temp;
		cout<<j<<"\t";
	}
	return 0;
}