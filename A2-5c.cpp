// ) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 
// columns. Assuming an array is used to store elements of the following matrices, 
// implement an efficient way that reduces the space requirement. 
// (c) Lower triangular Matrix. 

#include <bits/stdc++.h>
using namespace std;

class LowerTriangularMatrix {
    int n; // Size of matrix
    int *arr; // Array to store non-zero elements
public:
    LowerTriangularMatrix(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2]; // Only n(n+1)/2 elements needed for lower triangular matrix
    }
    void set(int i, int j, int value) {
        if (i >= j) {
            int index = (i * (i - 1)) / 2 + (j - 1); // Calculate index in 1D array
            arr[index] = value;
        }
    }
    int get(int i, int j) {
        if (i >= j) {
            int index = (i * (i - 1)) / 2 + (j - 1); // Calculate index in 1D array
            return arr[index];
        }
        return 0; // Upper triangular elements are zero
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= j) {
                    int index = (i * (i - 1)) / 2 + (j - 1);
                    cout << arr[index] << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    ~LowerTriangularMatrix() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter the size of the lower triangular matrix: ";
    cin >> size;
    LowerTriangularMatrix ltm(size);
    
    cout << "Enter the elements of the lower triangular matrix:\n";
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= i; j++) {
            int value;
            cout << "Element at (" << i << "," << j << "): ";
            cin >> value;
            ltm.set(i, j, value);
        }
    }
    
    cout << "The lower triangular matrix is:\n";
    ltm.display();
    
    return 0;
}
