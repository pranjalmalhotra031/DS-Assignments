// Design the logic to remove the duplicate elements from an Array and after the 
// deletion the array should contain the unique elements. 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[100], n;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // remove duplicates
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(arr[i] == arr[j]) {
                // Shift elements to the left
                for(int k = j; k < n - 1; ++k) {
                    arr[k] = arr[k + 1];
                }
                --n; // Reduce size of array
                j--; // recheck the current index
            }
        }
    }

    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
