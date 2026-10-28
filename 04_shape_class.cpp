// Practical 4: Class Shape with constructors and destructor
// Calculates perimeter of a circle and a rectangle
#include <iostream>
using namespace std;

class Shape {
private:
    double radius, length, width;
    static constexpr double PI = 3.14159265;

public:
    // Default constructor
    Shape() : radius(0), length(0), width(0) {
        cout << "Default constructor called\n";
    }

    // Parameterized constructor
    Shape(double r, double l, double w) : radius(r), length(l), width(w) {
        cout << "Parameterized constructor called\n";
    }

    // Copy constructor
    Shape(const Shape &s) : radius(s.radius), length(s.length), width(s.width) {
        cout << "Copy constructor called\n";
    }

    // Destructor
    ~Shape() {
        cout << "Destructor called\n";
    }

    double circlePerimeter() const { return 2 * PI * radius; }
    double rectanglePerimeter() const { return 2 * (length + width); }
};

int main() {
    double r, l, w;
    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Enter length and width of rectangle: ";
    cin >> l >> w;

    Shape s1(r, l, w);
    cout << "Perimeter of circle    : " << s1.circlePerimeter() << endl;
    cout << "Perimeter of rectangle : " << s1.rectanglePerimeter() << endl;

    Shape s2 = s1;  // demonstrates the copy constructor
    cout << "Copy's circle perimeter: " << s2.circlePerimeter() << endl;

    return 0;
}
