// Practical 5(b): Class Person - salary slip using constructors
// Total salary is divided into components:
//   Basic = 50%, HRA = 20%, DA = 30% of gross
//   Deductions: PF = 12% of basic, Professional tax = flat 200
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int SIZE = 10;

class Person {
private:
    char name[64];
    int age;
    char address[64];
    double salary;                       // gross salary
    double basic, hra, da, pf, tax, net;

    void calculate() {
        basic = 0.50 * salary;
        hra   = 0.20 * salary;
        da    = 0.30 * salary;
        pf    = 0.12 * basic;
        tax   = 200;
        net   = salary - pf - tax;
    }

public:
    // Default constructor
    Person() : age(0), salary(0), basic(0), hra(0), da(0), pf(0), tax(0), net(0) {
        strcpy(name, "N/A");
        strcpy(address, "N/A");
    }

    // Parameterized constructor: builds the salary components automatically
    Person(const char *n, int a, const char *addr, double s) : age(a), salary(s) {
        strncpy(name, n, 63);
        name[63] = '\0';
        strncpy(address, addr, 63);
        address[63] = '\0';
        calculate();
    }

    void displaySlip() const {
        cout << fixed << setprecision(2);
        cout << "\n------------- SALARY SLIP -------------\n"
             << "Name    : " << name << "\n"
             << "Age     : " << age << "\n"
             << "Address : " << address << "\n"
             << "---------------------------------------\n"
             << "Basic            : " << basic << "\n"
             << "HRA              : " << hra << "\n"
             << "DA               : " << da << "\n"
             << "Gross Salary     : " << salary << "\n"
             << "PF (deduction)   : " << pf << "\n"
             << "Prof. Tax        : " << tax << "\n"
             << "Net Salary       : " << net << "\n"
             << "---------------------------------------\n";
    }
};

int main() {
    Person people[SIZE];   // default constructor runs for all 10 objects

    for (int i = 0; i < SIZE; i++) {
        char name[64], address[64];
        int age;
        double salary;

        cout << "\nEnter details of person " << i + 1 << ":\n";
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

        people[i] = Person(name, age, address, salary);  // parameterized constructor
    }

    for (int i = 0; i < SIZE; i++)
        people[i].displaySlip();

    return 0;
}
