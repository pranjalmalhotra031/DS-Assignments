// a. Reverse the elements of an array 

#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // reverse the array
    int start = 0, end = n-1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
