// C++ Program to implement Rabin-Karp String Matching Algorithm

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void rabinKarp(string str, string pat) {
    if (str.length() && pat.length()) {          // check for empty strings
        int n = str.length();
        int m = pat.length();
        int i, j;                                // iterators for loops
        int s = 0, p = 0;                        // s = hash of string, p = hash of pattern
        const int pm = 256;                      // no of characters in alphabet
        const int q = 101;                       // large prime number
        int h = 1;                               // h = multiplier for MSB
        bool flag = false;

        // the value of h would be eqv to pow(pm, m-1)
        for (i = 0; i < m-1; i++)
            h = (h * pm) % q;

        // calculating initial hash for string and pattern
        for (i = 0; i < m; i++) {
            s = (pm * s + str[i]) % q;
            p = (pm * p + pat[i]) % q;
        }

        for (i = 0; i <= n-m; i++) {
            if (s == p) {                       // comparing hash of string and pattern
                for (j = 0; j < m; j++)
                    if (str[i+j] != pat[j])
                        break;
                if (j == m) {
                    cout<<"Pattern found at pos: "<<i+1<<endl;
                    flag = true;
                }
            }
            // calculating hash of next substring
            s = (pm * (s - h * str[i]) + str[i+m]) % q;
            if (s < 0)                          // still dont know why we do this :|
                s = s + q;
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

    string str, pat;
    getline(cin, str);
    getline(cin, pat);
    rabinKarp(str, pat);
    return 0;
}