// Develop a Menu driven program to demonstrate the following operations of Arrays 
// ——MENU——- 
// 1.CREATE 
// 2. DISPLAY 
// 3. INSERT 
// 4. DELETE 
// 5. LINEAR SEARCH 
// 6. EXIT 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100;

vector<int> arr;
int length;

// CREATE
void create() {
    cout << "Enter the number of elements: ";
    cin >> length;
    
    if(length > MAX_SIZE ||length <= 0) {
        cout << "Invalid size. Please enter a size between 1 and " << MAX_SIZE << ".\n";
        length = 0;
        arr.clear();
        return;
    }
    
    arr.resize(length);
    cout << "Enter the elements: \n";
    for(int i = 0; i < length; i++) {
        cin >> arr[i];
    }
    cout << "Array created successfully!\n";
}

// DISPLAY
void display() {
    if(length == 0) {
        cout << "Array is empty!\n";
        return;
    }
    
    cout << "Array elements: ";
    for(int i = 0; i < length; ++i) {
        cout << arr[i] << ' ';
    }
    cout << "\n";
}

// INSERT
void insert_element() {
    if(length == MAX_SIZE) {
        cout << "Array is full. Cannot insert.\n";
        return;
    }
    
    int element, position;
    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the position to insert (0 to " << length << "): ";;
    cin >> position;
    
    if(position < 0 || position > length) {
        cout << "Invalid position.\n";
        return;
    }
    
    arr.insert(arr.begin() + position, element);
    ++length;
    cout << "Element inserted successfully.\n";
}

// DELETE
void delete_element() {
    if(length == 0) {
        cout << "Array is empty. Cannot delete.\n";
        return;
    }
    
    int position;
    cout << "Enter the position to delete (0 to " << length - 1 << "); ";
    cin >> position;
    
    if(position < 0 || position >= length) {
        cout << "Invalid position.\n";
        return;
    }
    
    arr.erase(arr.begin() + position);
    --length;
    cout << "Element deleted successfully.\n";
}

//LINEAR SEARCH
int linear_search() {
    if(length == 0) {
        cout << "Array is empty. Cannot search.\n";
        return -1;
    }
    
    int element;
    cout << "Enter the element to search: ";
    cin >> element;
    
    for(int i =0; i < length; ++i) {
        if( arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int choice;
    
    do {
        cout << "\n---MENU---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: \n";
        cin >> choice;
        
        switch(choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_element();
                break;
            case 4:
                delete_element();
                break;
            case 5: {
                int result = linear_search();
                if(result != -1) {
                    cout << "Element found at position: " << result << "\n";
                }
                else {
                    cout << "Element not found.\n";
                }
                break;
            }
            case 6: 
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 6);
    
    return 0;
}
