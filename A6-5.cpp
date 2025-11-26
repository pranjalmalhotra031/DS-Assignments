// Write a program to check if a linked list is Circular Linked List or not.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Function to check if list is circular
bool isCircular(Node* head) {
    if (head == nullptr) 
        return false;    // empty list is not circular by definition
    
    Node* cur = head->next;

    // Traverse until null or reaching head again
    while (cur != nullptr && cur != head) {
        cur = cur->next;
    }

    return (cur == head);   // if we reached head -> circular
}

int main() {
    // Example 1: Circular Linked List
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = head1;  // making it circular

    cout << "List 1 is " 
         << (isCircular(head1) ? "Circular" : "Not Circular") << endl;

    // Example 2: Non-circular Linked List
    Node* head2 = new Node(5);
    head2->next = new Node(15);
    head2->next->next = new Node(25);

    cout << "List 2 is "
         << (isCircular(head2) ? "Circular" : "Not Circular") << endl;

    return 0;
}
