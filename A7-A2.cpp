//  Radix Sort (https://www.programiz.com/dsa/radix-sort) 

#include <iostream>
#include <vector>
using namespace std;

// -----------------------------
// Counting Sort used by Radix Sort
// Sorts arr[] according to the digit represented by exp
// -----------------------------

void countingSort(int arr[], int n, int exp) {
    vector<int> output(n);
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Convert count[i] to prefix sum array
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (stable)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// -----------------------------
// Radix Sort
// -----------------------------

void radixSort(int arr[], int n) {
    if (n == 0) return;

    // 1. Find maximum number to know number of digits
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    // 2. Apply Counting Sort for every digit (exp = 1, 10, 100, ...)
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    radixSort(arr, n);

    cout << "Sorted array (Radix Sort): ";
    printArray(arr, n);

    return 0;
}
