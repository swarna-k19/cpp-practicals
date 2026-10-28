// Practical 2: Effect of call by value and call by reference
#include <iostream>
using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByValue:     a = " << a << ", b = " << b << endl;
}

void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByReference: a = " << a << ", b = " << b << endl;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "\nBefore call:            x = " << x << ", y = " << y << endl;

    swapByValue(x, y);
    cout << "After call by value:    x = " << x << ", y = " << y << " (unchanged)\n\n";

    swapByReference(x, y);
    cout << "After call by reference: x = " << x << ", y = " << y << " (swapped)\n";

    return 0;
}
