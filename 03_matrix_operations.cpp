// Practical 3: Matrix operations using functions and switch case
#include <iostream>
using namespace std;

const int MAX = 10;

void readMatrix(int m[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> m[i][j];
}

void displayMatrix(int m[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
}

void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] + b[i][j];
}

void subtractMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] - b[i][j];
}

void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
}

void transposeMatrix(int a[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[j][i] = a[i][j];
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], res[MAX][MAX];
    int r1, c1, r2, c2, choice;

    do {
        cout << "\n===== MATRIX OPERATIONS =====\n"
             << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        case 2:
            cout << "Enter rows and columns (max " << MAX << "): ";
            cin >> r1 >> c1;
            cout << "Enter matrix A:\n";
            readMatrix(a, r1, c1);
            cout << "Enter matrix B:\n";
            readMatrix(b, r1, c1);
            if (choice == 1) {
                addMatrix(a, b, res, r1, c1);
                cout << "\nA + B =\n";
            } else {
                subtractMatrix(a, b, res, r1, c1);
                cout << "\nA - B =\n";
            }
            displayMatrix(res, r1, c1);
            break;

        case 3:
            cout << "Enter rows and columns of A: ";
            cin >> r1 >> c1;
            cout << "Enter rows and columns of B: ";
            cin >> r2 >> c2;
            if (c1 != r2) {
                cout << "Multiplication not possible (columns of A must equal rows of B).\n";
                break;
            }
            cout << "Enter matrix A:\n";
            readMatrix(a, r1, c1);
            cout << "Enter matrix B:\n";
            readMatrix(b, r2, c2);
            multiplyMatrix(a, b, res, r1, c1, c2);
            cout << "\nA x B =\n";
            displayMatrix(res, r1, c2);
            break;

        case 4:
            cout << "Enter rows and columns: ";
            cin >> r1 >> c1;
            cout << "Enter matrix:\n";
            readMatrix(a, r1, c1);
            transposeMatrix(a, res, r1, c1);
            cout << "\nTranspose =\n";
            displayMatrix(res, c1, r1);
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
