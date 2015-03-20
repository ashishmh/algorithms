// multiply and add two large integers

#include <iostream>
#include <string>
using namespace std;

string addNum(string n1, string n2);
string multiNum(string n1, string n2);
string multiSingle(string num, int n);
void printReverseStr(string str);

string addNum(string n1, string n2) {
    string num1, num2;
    // bigger number assigned to num1 and smaller to num2
    num1 = (n1.length() > n2.length()) ? n1 : n2;
    num2 = (n1.length() > n2.length()) ? n2 : n1;
    int len1 = num1.length();
    int len2 = num2.length();

    int x, i, carry = 0;
    string ans;
    
    for (i = 0; i < len2; i++) {
        x = (num1[i]-'0') + (num2[i]-'0') + carry;
        ans += (x % 10) + '0';
        carry = x/10;
    }
    
    while (i < len1) {
        x = (num1[i]-'0') + carry;
        ans += (x % 10) + '0';
        carry = x/10;
        i++;
    }
    
    if (carry > 0)
        ans += carry + '0';

    return ans;
}

string multiNum(string n1, string n2) {
    string num1, num2;
    // bigger number assigned to num1 and smaller to num2
    num1 = (n1.length() > n2.length()) ? n1 : n2;
    num2 = (n1.length() > n2.length()) ? n2 : n1;
    int len1 = num1.length();
    int len2 = num2.length();

    string ans, temp;

    for (int i = 0; i < len2; i++) {
        temp = multiSingle(num1, num2[i]-'0');
        for (int j = 0; j < i; j++)             // inserting appropriate number of zeros
            temp = '0' + temp;
        ans = addNum(temp, ans);
    }
    return ans;
}

string multiSingle(string num, int n) {
    int i, x, carry = 0;
    string ans;
    for (i = 0; i < num.length(); i++) {
        x = ( (num[i]-'0') * n ) + carry;
        ans += ('0' + x % 10);
        carry = x/10;
    }
    while (carry > 0) {
        ans += ('0' + carry % 10);
        carry = carry/10;
        i++;
    }
    return ans;
}

void printReverseStr(string str) {
    for (int i = str.length()-1; i >= 0; i--)
        cout<<str[i];
}

int main() {
    string num1, num2, ans;
    num1 = "987654321";             // storing 123456789
    num2 = "768";                   // storing 867
    ans = addNum(num1, num2);
    cout<<"sum: ";
    printReverseStr(ans);
    ans = multiNum(num1, num2);
    cout<<endl<<"product: ";
    printReverseStr(ans);
    cout<<endl;
    return 0;
}