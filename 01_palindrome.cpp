// Practical 1: Check whether a number and a string are palindromes
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isNumberPalindrome(long long n) {
    if (n < 0)
        return false;
    long long original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

bool isStringPalindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        while (left < right && !isalnum(static_cast<unsigned char>(s[left])))
            left++;
        while (left < right && !isalnum(static_cast<unsigned char>(s[right])))
            right--;
        if (tolower(static_cast<unsigned char>(s[left])) != tolower(static_cast<unsigned char>(s[right])))
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    long long num;
    cout << "Part A: Number Palindrome" << endl;
    cout << "Enter a number: ";
    cin >> num;
    if (isNumberPalindrome(num))
        cout << num << " is a palindrome number" << endl;
    else
        cout << num << " is not a palindrome number" << endl;

    string str;
    cin.ignore();
    cout << "\nPart B: String Palindrome" << endl;
    cout << "Enter a string: ";
    getline(cin, str);
    if (isStringPalindrome(str))
        cout << "\"" << str << "\" is a palindrome string" << endl;
    else
        cout << "\"" << str << "\" is not a palindrome string" << endl;

    return 0;
}
