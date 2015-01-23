/* The naïve string-matching procedure can be interpreted graphically as a sliding a 
pattern P[1 . . m] over the text T[1 . . n] and noting for which shift all of the characters 
in the pattern match the corresponding characters in the text. */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void naiveStringMatching(string str, string pattern) {
    if (str.length() && pattern.length()) {
        int n = str.length();
        int m = pattern.length();
        int s, j;
        bool flag = false;
        for (s=0; s <= n-m; s++) {
            j = 0;
            while (j < m && str[s+j] == pattern[j])
                ++j;
            if (j == m) {
                flag = true;
                cout<<"Pattern found at pos: "<<s+1<<endl;
                continue;
            }
        }
        if (!flag)
            cout<<"Pattern not found.."<<endl;
        return;
    }
    cout<<"Text or pattern cannot be empty.."<<endl;
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