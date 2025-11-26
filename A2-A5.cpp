// Given a fixed-length integer array arr, duplicate each occurrence of two (2), shifting the 
// remaining elements to the right.  
// Note that elements beyond the length of the original array are not written. Do the above 
// modifications to the input array in place and do not return anything. 
// https://leetcode.com/problems/duplicate-zeros/description/

#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int possible = 0;      // how many extra slots needed
    int end = n - 1;       // last index

    // First pass: count duplicate spaces
    for (int i = 0; i <= end - possible; i++) {
        if (arr[i] == 2) {
            // if this 2 is exactly at the boundary and cannot be duplicated fully
            if (i == end - possible) {
                arr[end] = 2;   // write only once
                end--;          // reduce array limit
                break;          // stop counting
            }
            possible++;          // this 2 will need an extra slot
        }
    }

    int i = end - possible;   // last working index
    int j = end;              // last index of final array

    // Second pass: modify from right to left
    while (i >= 0) {
        if (arr[i] == 2) {
            arr[j--] = 2;     // duplicate 2
            arr[j--] = 2;
        } else {
            arr[j--] = arr[i];
        }
        i--;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[1000];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    duplicateTwos(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
