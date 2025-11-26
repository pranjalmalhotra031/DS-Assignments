// c. Find the Transpose of a Matrix 

#include <iostream>
using namespace std;

int main() {
    int A[10][10], T[10][10];
    int m, n;

    cout << "Enter rows and columns for the matrix: ";
    cin >> m >> n;

    // Input elements of the matrix
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Compute transpose
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            T[j][i] = A[i][j];
        }
    }

    // Display the transpose
    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
