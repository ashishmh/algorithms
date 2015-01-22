/* The naïve string-matching procedure can be interpreted graphically as a sliding a 
pattern P[1 . . m] over the text T[1 . . n] and noting for which shift all of the characters 
in the pattern match the corresponding characters in the text. */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void naiveStringMatching(string str, string pattern) {
    int n = str.length();
    int m = pattern.length();
    int shift, j;
    for (shift = 0; shift <= n-m; shift++) {
        j = 0;
        while (j < m && str[shift+j] == pattern[j])
            ++j;
        if (j == m) {
            cout<<"Substring found at pos: "<<shift+1<<endl;
            return;
        }
    }
    cout<<"Substring not found.."<<endl;
	return;
}

int main() {
    freopen("input.txt","r",stdin);

    string str, pattern;
    getline(cin, str);
    getline(cin, pattern);
    naiveStringMatching(str, pattern);
    return 0;
}