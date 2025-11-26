// Write a program to implement the following operations on a Sparse Matrix, 
// assuming the matrix is represented using a triplet. 
// (c) Multiplication of two matrices. 

#include <iostream>
using namespace std;

#define MAX 100
// read a sparse matrix in triplet form
void readSparse(int t[][3]) {
    cout << "Enter rows, columns, and number of non-zero elements: ";
    cin >> t[0][0] >> t[0][1] >> t[0][2];

    cout << "Enter row, column, value for each non-zero element:\n";
    for (int i = 1; i <= t[0][2]; i++) {
        cin >> t[i][0] >> t[i][1] >> t[i][2];
    }
}

// print sparse matrix
void printSparse(int t[][3]) {
    cout << "\nRow\tCol\tVal\n";
    for (int i = 0; i <= t[0][2]; i++) {
        cout << t[i][0] << "\t" << t[i][1] << "\t" << t[i][2] << endl;
    }
}
// multiply two sparse matrices
void multiplySparse(int A[][3], int B[][3], int C[][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "\nMatrix dimensions do not match for multiplication. Cannot multiply.\n";
        C[0][2] = 0;
        return;
    }

    C[0][0] = A[0][0];
    C[0][1] = B[0][1];
    C[0][2] = 0;

    int k = 1;

    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= B[0][2]; j++) {
            if (A[i][1] == B[j][0]) {
                int row = A[i][0];
                int col = B[j][1];
                int val = A[i][2] * B[j][2];

                // Check if this position already exists in C
                bool found = false;
                for (int p = 1; p < k; p++) {
                    if (C[p][0] == row && C[p][1] == col) {
                        C[p][2] += val;
                        found = true;
                        break;
                    }
                }
                // If not found, add new entry
                if (!found) {
                    C[k][0] = row;
                    C[k][1] = col;
                    C[k][2] = val;
                    k++;
                }
            }
        }
    }
    C[0][2] = k - 1; // Update number of non-zero elements
}

int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];

    cout << "Input Sparse Matrix A:\n";
    readSparse(A);
    cout << "Input Sparse Matrix B:\n";
    readSparse(B);

    multiplySparse(A, B, C);

    cout << "\nSparse Matrix A:";
    printSparse(A);
    cout << "\nSparse Matrix B:";
    printSparse(B);
    cout << "\nResultant Sparse Matrix C (A * B):";
    printSparse(C);

    return 0;
}
