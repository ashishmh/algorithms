#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);

	int i,count = 0,n;
	cin>>n;
	for( i=2; i<n/2; i++ )
		if( n%i == 0 ) {
			count++;
			cout<<"Not a prime"<<endl;
			break;
		}
	if( !count )
		cout<<"Prime"<<endl;
	return 0;
}