// ) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 
// columns. Assuming an array is used to store elements of the following matrices, 
// implement an efficient way that reduces the space requirement. 
// (a) Diagonal Matrix

#include <bits/stdc++.h>
using namespace std;

class DiagonalMatrix {
    int n; // Size of matrix
    int *arr; // Array to store non-zero elements
public:
    DiagonalMatrix(int size) {
        n = size;
        arr = new int[n]; // Only n elements needed for diagonal matrix
    }
    void set(int i, int j, int value) {
        if (i == j) {
            arr[i - 1] = value; // Store value only if it's on the diagonal
        }
    }
    int get(int i, int j) {
        if (i == j) {
            return arr[i - 1]; // Return value if it's on the diagonal
        }
        return 0; // Off-diagonal elements are zero
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    cout << arr[i - 1] << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    ~DiagonalMatrix() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter the size of the diagonal matrix: ";
    cin >> size;
    DiagonalMatrix dm(size);
    
    cout << "Enter the diagonal elements:\n";
    for (int i = 1; i <= size; i++) {
        int value;
        cout << "Element at (" << i << "," << i << "): ";
        cin >> value;
        dm.set(i, i, value);
    }
    
    cout << "The diagonal matrix is:\n";
    dm.display();
    
    return 0;
}
