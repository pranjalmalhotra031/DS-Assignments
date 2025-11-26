// Write a program to implement the following operations on a Sparse Matrix, 
// assuming the matrix is represented using a triplet. 
// (a) Transpose of a matrix. 

#include <bits/stdc++.h>
using namespace std;

class SparseMatrix {
    int rows, cols, nonZeroCount;
    vector<tuple<int, int, int>> triplet; // (row, col, value)
public:
    SparseMatrix(int r, int c) : rows(r), cols(c), nonZeroCount(0) {}

    void addElement(int r, int c, int value) {
        if (value != 0) {
            triplet.push_back(make_tuple(r, c, value));
            nonZeroCount++;
        }
    }

    SparseMatrix transpose() {
        SparseMatrix transposed(cols, rows);
        for (const auto &elem : triplet) {
            int r = get<0>(elem);
            int c = get<1>(elem);
            int value = get<2>(elem);
            transposed.addElement(c, r, value);
        }
        return transposed;
    }
    void display() {
        cout << "Row\tCol\tValue\n";
        for (const auto &elem : triplet) {
            cout << get<0>(elem) << "\t" << get<1>(elem) << "\t" << get<2>(elem) << "\n";
        }
    }
};

int main() {
    SparseMatrix sm(4, 5);
    sm.addElement(0, 1, 5);
    sm.addElement(1, 3, 8);
    sm.addElement(2, 0, 3);
    sm.addElement(3, 4, 6);

    cout << "Original Sparse Matrix (Triplet Form):\n";
    sm.display();

    SparseMatrix transposed = sm.transpose();
    cout << "\nTransposed Sparse Matrix (Triplet Form):\n";
    transposed.display();

    return 0;
}
