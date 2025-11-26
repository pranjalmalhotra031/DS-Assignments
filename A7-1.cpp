// Write a program to implement following sorting techniques: 
// a. Selection Sort 
// b. Insertion Sort 
// c. Bubble Sort 
// d. Merge Sort 
// e. Quick Sort 

#include <iostream>
using namespace std;

// -----------------------------
// Utility: Print Array
// -----------------------------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// -----------------------------
// a. Selection Sort
// -----------------------------
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        swap(arr[i], arr[min_index]);
    }
}

// -----------------------------
// b. Insertion Sort
// -----------------------------
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// -----------------------------
// c. Bubble Sort
// -----------------------------
void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break; // optimization
    }
}

// -----------------------------
// d. Merge Sort
// -----------------------------
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// -----------------------------
// e. Quick Sort
// -----------------------------
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// -----------------------------
// Main (Menu Driven)
// -----------------------------
int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;

    do {
        cout << "\n----- SORTING MENU -----\n";
        cout << "1. Selection Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int temp[100];
        for (int i = 0; i < n; i++)
            temp[i] = arr[i]; // copy original array for each sort

        switch (choice) {
            case 1:
                selectionSort(temp, n);
                cout << "Sorted Array (Selection Sort): ";
                printArray(temp, n);
                break;

            case 2:
                insertionSort(temp, n);
                cout << "Sorted Array (Insertion Sort): ";
                printArray(temp, n);
                break;

            case 3:
                bubbleSort(temp, n);
                cout << "Sorted Array (Bubble Sort): ";
                printArray(temp, n);
                break;

            case 4:
                mergeSort(temp, 0, n - 1);
                cout << "Sorted Array (Merge Sort): ";
                printArray(temp, n);
                break;

            case 5:
                quickSort(temp, 0, n - 1);
                cout << "Sorted Array (Quick Sort): ";
                printArray(temp, n);
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
