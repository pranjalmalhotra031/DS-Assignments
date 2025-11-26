// Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an 
// inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to 
// count the number of inversions in an array. 

#include <bits/stdc++.h>
using namespace std;

// Merge two halves and count inversions
long long mergeAndCount(vector<long long>& arr, int left, int mid, int right) {
    vector<long long> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<long long> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    long long inversions = 0;
    int n1 = L.size(), n2 = R.size();

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inversions += (n1 - i); // remaining left elements form inversions
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    return inversions;
}

// Recursive merge sort + inversion counter
long long countInversions(vector<long long>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    
    long long inversions = 0;
    inversions += countInversions(arr, left, mid);
    inversions += countInversions(arr, mid + 1, right);
    inversions += mergeAndCount(arr, left, mid, right);

    return inversions;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<long long> A(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) cin >> A[i];

    long long result = countInversions(A, 0, n - 1);
    cout << "Number of inversions: " << result << endl;

    return 0;
}
