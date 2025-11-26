// ) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 
// columns. Assuming an array is used to store elements of the following matrices, 
// implement an efficient way that reduces the space requirement. 
// (d) Upper triangular Matrix. 

#include <bits/stdc++.h>
using namespace std;

class UpperTriangularMatrix {
    int n; // Size of matrix
    int *arr; // Array to store non-zero elements
public:
    UpperTriangularMatrix(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2]; // Only n(n+1)/2 elements needed for upper triangular matrix
    }
    void set(int i, int j, int value) {
        if (i <= j) {
            int index = (j * (j - 1)) / 2 + (i - 1); // Calculate index in 1D array
            arr[index] = value;
        }
    }
    int get(int i, int j) {
        if (i <= j) {
            int index = (j * (j - 1)) / 2 + (i - 1); // Calculate index in 1D array
            return arr[index];
        }
        return 0; // Lower triangular elements are zero
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i <= j) {
                    int index = (j * (j - 1)) / 2 + (i - 1);
                    cout << arr[index] << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    ~UpperTriangularMatrix() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter the size of the upper triangular matrix: ";
    cin >> size;
    UpperTriangularMatrix utm(size);
    
    cout << "Enter the elements of the upper triangular matrix:\n";
    for (int i = 1; i <= size; i++) {
        for (int j = i; j <= size; j++) {
            int value;
            cout << "Element at (" << i << "," << j << "): ";
            cin >> value;
            utm.set(i, j, value);
        }
    }
    
    cout << "The upper triangular matrix is:\n";
    utm.display();
    
    return 0;
}
