// Write a program to count the number of occurrences of a given key in a singly linked 
// list and then delete all the occurrences.  
// Input: Linked List :  1->2->1->2->1->3->1 , key:  1                                                                    
// Output: Count: 4 ,  Updated Linked List: 2->2->3. 

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at end
    void insert(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }

    // Count occurrences + delete them
    int deleteAllOccurrences(int key) {
        int count = 0;

        // Delete from beginning if head matches
        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        if (!head) return count;

        // Delete in the middle/end
        Node* cur = head;
        while (cur->next) {
            if (cur->next->data == key) {
                Node* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                count++;
            } else {
                cur = cur->next;
            }
        }

        return count;
    }

    void display() const {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << "->";
            cur = cur->next;
        }
        cout << "\n";
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    // Sample input
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        list.insert(arr[i]);

    int key = 1;

    cout << "Original Linked List: ";
    list.display();

    int count = list.deleteAllOccurrences(key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    list.display();

    return 0;
}
