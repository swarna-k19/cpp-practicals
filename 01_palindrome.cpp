// Practical 1: Check whether a number and a string are palindromes
#include <iostream>
#include <string>
using namespace std;

bool isNumberPalindrome(long long n) {
    if (n < 0) return false;
    long long original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

bool isStringPalindrome(const string &s) {
    int i = 0, j = static_cast<int>(s.size()) - 1;
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

int main() {
    long long num;
    string str;

    cout << "Enter a number: ";
    cin >> num;
    cout << num << (isNumberPalindrome(num) ? " is" : " is not") << " a palindrome number.\n";

    cout << "Enter a string (no spaces): ";
    cin >> str;
    cout << str << (isStringPalindrome(str) ? " is" : " is not") << " a palindrome string.\n";

    return 0;
}
