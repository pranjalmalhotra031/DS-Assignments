// Design the Logic to Find a Missing Number in a Sorted Array. Given an array of 
// n-1 distinct integers in the range of 1 to n, find the missing number in it in a Sorted 
// Array 
// (a) Linear time 

#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(int arr[], int n) {
    // expected sum of first n natural numbers
    int expectedSum = n * (n + 1) / 2;
    // actual sum of the elements in the array
    int actualSum = 0;
    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }
    // missing number = expected sum - actual sum
    return expectedSum - actualSum;
}
int main() {
    int arr[] = {1, 2, 4, 5, 6}; //  missing number 3
    int n = sizeof(arr) / sizeof(arr[0]) + 1; // bcz one number is missing
    int missingNumber = findMissingNumber(arr, n);
    cout << "The missing number is: " << missingNumber << endl;
    return 0;
}
