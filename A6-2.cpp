// Display all the node values in a circular linked list, repeating value of head node at the 
// end too.  
// Input: 20 → 100 → 40 → 80 → 60,  
// Output:  20 100 40 80 60 20. 

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Display all nodes and repeat head value at end
void displayCircular(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* cur = head;
    cout << cur->data << " ";  // print head first
    cur = cur->next;

    // traverse until we reach head again
    while (cur != head) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    // repeat head value
    cout << head->data << "\n";
}

int main() {
    // Example: 20 → 100 → 40 → 80 → 60 → back to 20
    Node* head = new Node(20);
    head->next = new Node(100);
    head->next->next = new Node(40);
    head->next->next->next = new Node(80);
    head->next->next->next->next = new Node(60);
    head->next->next->next->next->next = head; // make circular

    cout << "Circular List Output: ";
    displayCircular(head);

    return 0;
}
