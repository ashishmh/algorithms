// multiply two large integers and store result in array

#include <iostream>
#include <string>
using namespace std;

int bigMultiply(string str, int n, int *result);
void printReverseArr(int *arr, int size);

int bigMultiply(string str, int n, int *result) {
    int i, x, digits = 0, carry = 0;
    for (i = 0; i < str.length(); i++) {
        // str[i]-48 is for adjusting ASCII value
        x = ( (str[i]-48) * n ) + carry;
        result[i] = x % 10;
        digits++;
        carry = x/10;
    }
    while (carry > 0) {
        result[i] = carry % 10;
        carry = carry/10;
        digits++; i++;
    }
    return digits;
}

void printReverseArr(int *arr, int size) {
    for (int i = size-1; i >=0; i--)
        cout<<arr[i];
}

int main() {
    string str = "5555555544";  // storing 4455555555, it is first multiplicand
    int n = 337;                // second multiplicand
    int result[200];            // stores the result upto 200 digits
    int digits;                 // gets no of digits in result
    digits = bigMultiply(str, n, result);
    printReverseArr(result, digits);
    cout<<endl<<"no of digits: "<<digits;
    cout<<endl;
    return 0;
}