//  Find two numbers in an array whose difference equals K. Given an array arr[] and a 
// positive integer k, the task is to count all pairs (i, j) such that i < j and absolute value of 
// (arr[i] - arr[j]) is equal to k. 
// https://www.geeksforgeeks.org/dsa/count-pairs-difference-equal-k/ 

#include <bits/stdc++.h>
using namespace std;

long long countPairsWithDiffK_sort(vector<long long> arr, long long k) {
    int n = arr.size();
    if (n < 2) return 0;
    sort(arr.begin(), arr.end());
    int i = 0, j = 1;
    long long count = 0;

    while (i < n && j < n) {
        if (i == j) { // to ensure i < j
            j++;
            continue;
        }
        long long diff = arr[j] - arr[i];
        if (diff == k) {
            // When values can repeat, we should count all pairs between equal blocks.
            // But simpler: advance j by 1 and increment count by 1 repeatedly (works too),
            // because sort ensures we will eventually consider all pairs with i < j.
            count++;
            j++;
        } else if (diff < k) {
            j++;
        } else { // diff > k
            i++;
        }
    }
    return count;
}

int main() {
    int n;
    long long k;
    cout << "Enter n and k: ";
    if (!(cin >> n >> k)) return 0;
    vector<long long> arr(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    cout << "Number of pairs with |arr[i]-arr[j]| == " << k << " is: "
         << countPairsWithDiffK_sort(arr, k) << "\n";
    return 0;
}
