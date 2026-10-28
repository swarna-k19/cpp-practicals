// Practical 5(a): Class Person - inline function to find youngest and eldest age
#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 10;

class Person {
private:
    char name[64];
    int age;
    char address[64];
    double salary;

public:
    void input() {
        cout << "Name   : ";
        cin >> ws;
        cin.getline(name, 64);
        cout << "Age    : ";
        cin >> age;
        cout << "Address: ";
        cin >> ws;
        cin.getline(address, 64);
        cout << "Salary : ";
        cin >> salary;
    }

    int getAge() const { return age; }
};

// Inline function to get youngest and eldest age using an array of Person
inline void findYoungestEldest(const Person p[], int n, int &youngest, int &eldest) {
    youngest = eldest = p[0].getAge();
    for (int i = 1; i < n; i++) {
        if (p[i].getAge() < youngest) youngest = p[i].getAge();
        if (p[i].getAge() > eldest) eldest = p[i].getAge();
    }
}

int main() {
    Person people[SIZE];
    int youngest, eldest;

    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter details of person " << i + 1 << ":\n";
        people[i].input();
    }

    findYoungestEldest(people, SIZE, youngest, eldest);
    cout << "\nYoungest age: " << youngest << endl;
    cout << "Eldest age  : " << eldest << endl;

    return 0;
}
