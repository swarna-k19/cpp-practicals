// Practical 9: Swap two numbers (from two classes) using a friend function
#include <iostream>
using namespace std;

class ClassB;  // forward declaration

class ClassA {
private:
    int num;

public:
    ClassA(int n = 0) : num(n) {}
    void display() const { cout << "ClassA number: " << num << endl; }
    friend void swapNumbers(ClassA &, ClassB &);
};

class ClassB {
private:
    int num;

public:
    ClassB(int n = 0) : num(n) {}
    void display() const { cout << "ClassB number: " << num << endl; }
    friend void swapNumbers(ClassA &, ClassB &);
};

// Friend function: can access private members of both classes
void swapNumbers(ClassA &a, ClassB &b) {
    int temp = a.num;
    a.num = b.num;
    b.num = temp;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    ClassA a(x);
    ClassB b(y);

    cout << "\nBefore swapping:\n";
    a.display();
    b.display();

    swapNumbers(a, b);

    cout << "\nAfter swapping:\n";
    a.display();
    b.display();

    return 0;
}
