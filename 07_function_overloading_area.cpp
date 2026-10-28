// Practical 7: Area of circle, rectangle and triangle using function overloading
#include <iostream>
using namespace std;

const double PI = 3.14159265;

// Circle: AREA(radius)
double AREA(double radius) {
    return PI * radius * radius;
}

// Rectangle: AREA(length, width)
double AREA(double length, double width) {
    return length * width;
}

// Triangle: AREA(base, height, flag) - the extra char distinguishes it from rectangle
double AREA(double base, double height, char /*triangle*/) {
    return 0.5 * base * height;
}

int main() {
    double r, l, w, b, h;

    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Area of circle    = " << AREA(r) << endl;

    cout << "Enter length and width of rectangle: ";
    cin >> l >> w;
    cout << "Area of rectangle = " << AREA(l, w) << endl;

    cout << "Enter base and height of triangle: ";
    cin >> b >> h;
    cout << "Area of triangle  = " << AREA(b, h, 't') << endl;

    return 0;
}
