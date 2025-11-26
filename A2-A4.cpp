// Sort an array of 0s, 1s and 2s - Dutch National Flag Problem 
// Given an array arr[] consisting of only 0s, 1s, and 2s. The objective is to sort the array, i.e., 
// put all 0s first, then all 1s and all 2s in last. 
// https://www.geeksforgeeks.org/dsa/sort-an-array-of-0s-1s-and-2s/ 

#include <iostream>
using namespace std;

void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int arr[100000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort012(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
