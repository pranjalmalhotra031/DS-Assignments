// Design the Logic to Find a Missing Number in a Sorted Array. Given an array of 
// n-1 distinct integers in the range of 1 to n, find the missing number in it in a Sorted 
// Array 
// Using binary search. 

#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int left = 0, right = n - 2; // n-1 elements in the array
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Check if missing number is in the left half
        if (arr[mid] != mid + 1) {
            right = mid - 1;
        } else {
            // Missing number is in the right half
            left = mid + 1;
        }
    }
    // The missing number is left + 1
    return left + 1;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6}; // missing number 3
    int n = sizeof(arr) / sizeof(arr[0]) + 1; // bcz one number is missing
    int missingNumber = findMissingNumber(arr, n);
    cout << "The missing number is: " << missingNumber << endl;
    return 0;
}
