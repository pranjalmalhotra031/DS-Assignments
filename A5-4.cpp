// Write a program to reverse a linked list. 
// Input: 1->2->3->4->NULL 
// Output: 4->3->2->1->NULL

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
        if (!head)
            head = node;
        else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* cur = head;
        Node* nextNode = nullptr;

        while (cur) {
            nextNode = cur->next;  // store next
            cur->next = prev;      // reverse pointer
            prev = cur;            // move prev
            cur = nextNode;        // move current
        }

        head = prev;
    }

    void display() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data << "->";
            cur = cur->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    // Input: 1->2->3->4->NULL
    int arr[] = {1,2,3,4};
    for (int x : arr) list.insert(x);

    cout << "Original List: ";
    list.display();

    list.reverse();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
