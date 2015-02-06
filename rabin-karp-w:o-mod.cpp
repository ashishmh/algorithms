// C++ Program to implement Rabin-Karp String Matching Algorithm

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int power(int ,int);

void rabinKarp(string str, string pat) {
	int s = str.length();
	int p = pat.length();
	int i ,j;
	int hp = 0, hs = 0;
	int prime = 17;
	bool flag = false;
	// calculating initial hash of pattern and first substring
	for (i = 0; i < p; i++) {
		hp = (hp + power(prime, p-1-i) * pat[i]);
		hs = (hs + power(prime, p-1-i) * str[i]);
	}
	for (i = 0; i <= s-p; i++) {
		if (hs == hp) {
			for (j = 0; j < p; j++)
				if (str[j+i] != pat[j])
					break;
			if (j == p) {
				cout<<"Pattern found at location "<<i+1<<endl;
				flag = true;
			}
		}
		// calculating the hash of next substring
		hs = (prime * (hs - (power(prime, p-1)) * str[i]) + str[p+i]);
	}
	if (!flag)
		cout<<"Pattern not found!"<<endl;
	return;
}

int power(int base, int power) {
	int result = 1;
	for (int i = 0; i < power; i++)
		result = result * base;
	return result;
}

int main() {
	freopen("input.txt","r",stdin);
	
	string str, pat;
	getline(cin, str);
	getline(cin, pat);
	rabinKarp(str, pat);
	return 0;
}