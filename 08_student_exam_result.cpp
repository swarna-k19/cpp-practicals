// Practical 8: Student -> Exam -> Result (Multilevel Inheritance)
#include <iostream>
#include <string>
using namespace std;

const int SUBJECTS = 6;

class Student {
protected:
    int rollNo;
    string name;

public:
    void inputStudent() {
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter name: ";
        cin >> ws;
        getline(cin, name);
    }

    void displayStudent() const {
        cout << "Roll No : " << rollNo << "\nName    : " << name << endl;
    }
};

class Exam : public Student {
protected:
    float marks[SUBJECTS];

public:
    void inputMarks() {
        for (int i = 0; i < SUBJECTS; i++) {
            cout << "Enter marks in subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void displayMarks() const {
        for (int i = 0; i < SUBJECTS; i++)
            cout << "Subject " << i + 1 << ": " << marks[i] << endl;
    }
};

class Result : public Exam {
private:
    float total;
    float percentage;

public:
    void compute() {
        total = 0;
        for (int i = 0; i < SUBJECTS; i++)
            total += marks[i];
        percentage = total / SUBJECTS;
    }

    void displayResult() const {
        displayStudent();
        displayMarks();
        cout << "Total      : " << total << endl;
        cout << "Percentage : " << percentage << "%" << endl;
    }
};

int main() {
    Result r;

    r.inputStudent();
    r.inputMarks();
    r.compute();

    cout << "\n------- RESULT -------\n";
    r.displayResult();

    cout << "\nInheritance type: Multilevel inheritance "
            "(Student -> Exam -> Result)\n";
    return 0;
}
