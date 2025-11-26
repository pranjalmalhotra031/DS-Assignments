// A slightly improved selection sort – We know that selection sort algorithm takes the minimum on 
// every pass on the array, and place it at its correct position. The idea is to take also the maximum on 
// every pass and place it at its correct position. So in every pass, we keep track of both maximum and 
// minimum and array becomes sorted from both ends. Implement this logic. 

#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0;          // beginning index
    int right = n - 1;     // ending index

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        // If first element is greater than last, swap indices
        if (arr[minIndex] > arr[maxIndex])
            swap(minIndex, maxIndex);

        for (int i = left + 1; i < right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            else if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Place minimum at left
        swap(arr[left], arr[minIndex]);

        // If maxIndex was at left, it moved due to previous swap
        if (maxIndex == left)
            maxIndex = minIndex;

        // Place maximum at right
        swap(arr[right], arr[maxIndex]);

        // Move boundaries inward
        left++;
        right--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted array (Improved Selection Sort): ";
    printArray(arr, n);

    return 0;
}
