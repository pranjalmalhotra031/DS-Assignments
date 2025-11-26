// Develop a menu driven program for the following operations on a Singly Linked 
// List. 
// (a) Insertion at the beginning. 
// (b) Insertion at the end. 
// (c) Insertion in between (before or after a node having a specific value, say 'Insert a 
// new Node 35 before/after the Node 30'). 
// (d) Deletion from the beginning. 
// (e) Deletion from the end. 
// (f) Deletion of a specific node, say 'Delete Node 60'). 
// (g) Search for a node and display its position from head. 
// (h) Display all the node values.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
}

;

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    bool isEmpty() const { return head == nullptr; }

    // (a) Insert at beginning
    void insertAtBeginning(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        cout << val << " inserted at the beginning.\n";
    }

    // (b) Insert at end
    void insertAtEnd(int val) {
        Node* node = new Node(val);
        if (isEmpty()) {
            head = node;
        } else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
        cout << val << " inserted at the end.\n";
    }

    // (c1) Insert before a node with specific value (first occurrence)
    void insertBeforeValue(int target, int val) {
        if (isEmpty()) {
            cout << "List is empty. Cannot insert before " << target << ".\n";
            return;
        }

        // If target is at head
        if (head->data == target) {
            insertAtBeginning(val);
            return;
        }

        Node* prev = nullptr;
        Node* cur = head;
        while (cur && cur->data != target) {
            prev = cur;
            cur = cur->next;
        }

        if (!cur) {
            cout << "Value " << target << " not found.\n";
            return;
        }

        Node* node = new Node(val);
        prev->next = node;
        node->next = cur;
        cout << val << " inserted before " << target << ".\n";
    }

    // (c2) Insert after a node with specific value (first occurrence)
    void insertAfterValue(int target, int val) {
        Node* cur = head;
        while (cur && cur->data != target) cur = cur->next;

        if (!cur) {
            cout << "Value " << target << " not found.\n";
            return;
        }

        Node* node = new Node(val);
        node->next = cur->next;
        cur->next = node;
        cout << val << " inserted after " << target << ".\n";
    }

    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (isEmpty()) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from the beginning.\n";
        delete temp;
    }

    // (e) Deletion from the end
    void deleteFromEnd() {
        if (isEmpty()) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (!head->next) { // only one node
            cout << "Deleted " << head->data << " from the end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* prev = nullptr;
        Node* cur = head;
        while (cur->next) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = nullptr;
        cout << "Deleted " << cur->data << " from the end.\n";
        delete cur;
    }

    // (f) Deletion of a specific node (first occurrence of value)
    void deleteValue(int val) {
        if (isEmpty()) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (head->data == val) {
            deleteFromBeginning();
            return;
        }
        Node* prev = nullptr;
        Node* cur = head;
        while (cur && cur->data != val) {
            prev = cur;
            cur = cur->next;
        }
        if (!cur) {
            cout << "Value " << val << " not found.\n";
            return;
        }
        prev->next = cur->next;
        cout << "Deleted " << cur->data << ".\n";
        delete cur;
    }

    // (g) Search for a node and display its position from head (1-based)
    void search(int val) const {
        Node* cur = head;
        int pos = 1;
        while (cur) {
            if (cur->data == val) {
                cout << "Value " << val << " found at position " << pos << " from head.\n";
                return;
            }
            cur = cur->next;
            ++pos;
        }
        cout << "Value " << val << " not found in the list.\n";
    }

    // (h) Display all node values
    void display() const {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }
        cout << "List: ";
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << "\n";
    }

    // Destructor to free nodes
    ~SinglyLinkedList() {
        while (!isEmpty()) deleteFromBeginning();
    }
};

int main() {
    SinglyLinkedList list;
    int choice;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert BEFORE a value\n";
        cout << "4. Insert AFTER a value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific value\n";
        cout << "8. Search for a value\n";
        cout << "9. Display list\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }

        int val, target;
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter target value (insert before): ";
                cin >> target;
                cout << "Enter new value to insert: ";
                cin >> val;
                list.insertBeforeValue(target, val);
                break;
            case 4:
                cout << "Enter target value (insert after): ";
                cin >> target;
                cout << "Enter new value to insert: ";
                cin >> val;
                list.insertAfterValue(target, val);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteValue(val);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> val;
                list.search(val);
                break;
            case 9:
                list.display();
                break;
            case 10:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 10);

    return 0;
}
