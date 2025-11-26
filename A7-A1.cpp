//  Counting Sort ( https://www.programiz.com/dsa/counting-sort) 

#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n) {
    if (n == 0) return;

    // 1. Find the maximum value
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    // 2. Create count array
    vector<int> count(maxVal + 1, 0);

    // 3. Store the frequency of each value
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // 4. Modify count array to store prefix sums
    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    // 5. Build output array (stable sorting)
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 6. Copy sorted values back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    countingSort(arr, n);

    cout << "Sorted array (Counting Sort): ";
    printArray(arr, n);

    return 0;
}
