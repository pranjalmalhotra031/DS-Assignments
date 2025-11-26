// ) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 
// columns. Assuming an array is used to store elements of the following matrices, 
// implement an efficient way that reduces the space requirement. 
// (e) Symmetric Matrix 

#include <bits/stdc++.h>
using namespace std;

class SymmetricMatrix {
    int n; // Size of matrix
    int *arr; // Array to store non-zero elements
public:
    SymmetricMatrix(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2]; // Only n(n+1)/2 elements needed for symmetric matrix
    }
    void set(int i, int j, int value) {
        if (i >= j) {
            int index = (i * (i - 1)) / 2 + (j - 1); // Calculate index in 1D array
            arr[index] = value;
        } else {
            int index = (j * (j - 1)) / 2 + (i - 1); // Symmetric position
            arr[index] = value;
        }
    }
    int get(int i, int j) {
        if (i >= j) {
            int index = (i * (i - 1)) / 2 + (j - 1); // Calculate index in 1D array
            return arr[index];
        } else {
            int index = (j * (j - 1)) / 2 + (i - 1); // Symmetric position
            return arr[index];
        }
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= j) {
                    int index = (i * (i - 1)) / 2 + (j - 1);
                    cout << arr[index] << " ";
                } else {
                    int index = (j * (j - 1)) / 2 + (i - 1);
                    cout << arr[index] << " ";
                }
            }
            cout << endl;
        }
    }
    ~SymmetricMatrix() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter the size of the symmetric matrix: ";
    cin >> size;
    SymmetricMatrix sm(size);
    
    cout << "Enter the elements of the symmetric matrix:\n";
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= i; j++) {
            int value;
            cout << "Element at (" << i << "," << j << "): ";
            cin >> value;
            sm.set(i, j, value);
        }
    }
    
    cout << "The symmetric matrix is:\n";
    sm.display();
    
    return 0;
}
