// Write a program to find sum of every row and every column in a two-dimensional array.  

#include <iostream>
using namespace std;

int main() {
    int A[10][10];
    int m, n;

    cout << "Enter rows and columns for the matrix: ";
    cin >> m >> n;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // sum of each row
    cout << "Sum of each row:\n";
    for (int i = 0; i < m; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += A[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }

    // sum of each column
    cout << "Sum of each column:\n";
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += A[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }
    return 0;
}
