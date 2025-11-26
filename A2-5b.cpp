// ) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 
// columns. Assuming an array is used to store elements of the following matrices, 
// implement an efficient way that reduces the space requirement. 
// (b) Tri-diagonal Matrix. 

#include <bits/stdc++.h>
using namespace std;

class TriDiagonalMatrix {
    int n; // Size of matrix
    int *arr; // Array to store non-zero elements 
public:
    TriDiagonalMatrix(int size) {
        n = size;
        arr = new int[3 * n - 2]; // Only 3n-2 elements needed for tri-diagonal matrix
    }
    void set(int i, int j, int value) {
        if (i - j == 1) {
            arr[i - 2] = value; // Lower diagonal
        } else if (i - j == 0) {
            arr[n - 1 + i - 1] = value; // Main diagonal
        } else if (i - j == -1) {
            arr[2 * n - 1 + i - 1] = value; // Upper diagonal
        }
    }
    int get(int i, int j) {
        if (i - j == 1) {
            return arr[i - 2]; // Lower diagonal
        } else if (i - j == 0) {
            return arr[n - 1 + i - 1]; // Main diagonal
        } else if (i - j == -1) {
            return arr[2 * n - 1 + i - 1]; // Upper diagonal
        }
        return 0; // Other elements are zero
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i - j == 1) {
                    cout << arr[i - 2] << " ";
                } else if (i - j == 0) {
                    cout << arr[n - 1 + i - 1] << " ";
                } else if (i - j == -1) {
                    cout << arr[2 * n - 1 + i - 1] << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    ~TriDiagonalMatrix() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter the size of the tri-diagonal matrix: ";
    cin >> size;
    TriDiagonalMatrix tdm(size);
    
    cout << "Enter the elements of the tri-diagonal matrix:\n";
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            int value;
            cout << "Element at (" << i << "," << j << "): ";
            cin >> value;
            tdm.set(i, j, value);
        }
    }
    
    cout << "The tri-diagonal matrix is:\n";
    tdm.display();
    
    return 0;
}
