// Write a program to implement the following operations on a Sparse Matrix, 
// assuming the matrix is represented using a triplet. 
// (b) Addition of two matrices. 

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

// add two sparse matrices
void addSparse(int A[][3], int B[][3], int C[][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "\nMatrix dimensions do not match. Cannot add.\n";
        C[0][2] = 0;
        return;
    }

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    int i = 1, j = 1, k = 1;

    // Merge logic like merge-sort
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else {  
            // Same row & col
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    // Copy remaining elements
    while (i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;   // total non-zero entries
}

int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];

    cout << "Enter first sparse matrix:\n";
    readSparse(A);

    cout << "Enter second sparse matrix:\n";
    readSparse(B);

    addSparse(A, B, C);

    cout << "\nSparse Matrix A:";
    printSparse(A);

    cout << "\nSparse Matrix B:";
    printSparse(B);

    cout << "\nResultant Sparse Matrix (A + B):";
    printSparse(C);

    return 0;
}
