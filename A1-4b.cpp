// b. Find the matrix multiplication 

#include <iostream>
using namespace std;

int main() {
    int A[10][10], B[10][10], C[10][10];
    int m, n, p, q;

    cout << "Enter rows and columns for first matrix: ";
    cin >> m >> n;
    cout << "Enter rows and columns for second matrix: ";
    cin >> p >> q;

    // check if multiplication is possible
    if (n != p) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    // Input elements of first matrix
    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    // Input elements of second matrix
    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            cin >> B[i][j];

    // Initialize result matrix C to zero
    for (int i = 0; i < m; i++)
        for (int j = 0; j < q; j++)
            C[i][j] = 0;

    // Perform matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display the result
    cout << "Resultant matrix after multiplication:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
