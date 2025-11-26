//  Write a program to count the total number of distinct elements in an array of 
// length n.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    int distinctCount = 1; // at least one element if array not empty

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            distinctCount++;
        }
    }

    cout << "Total number of distinct elements = " << distinctCount << endl;

    return 0;
}
