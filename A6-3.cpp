// Write a program to find size of 
// i. Doubly Linked List.  
// ii. Circular Linked List. 

#include <iostream>
using namespace std;

/*===========================
   Doubly Linked List Nodes
===========================*/
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d) : data(d), prev(nullptr), next(nullptr) {}
};

/*===========================
   Circular Linked List Nodes
===========================*/
struct CNode {
    int data;
    CNode* next;
    CNode(int d) : data(d), next(nullptr) {}
};

/*===========================
   SIZE of Doubly Linked List
===========================*/
int sizeOfDoubly(DNode* head) {
    int count = 0;
    DNode* cur = head;
    while (cur) {
        count++;
        cur = cur->next;
    }
    return count;
}

/*===========================
   SIZE of Circular Linked List
===========================*/
int sizeOfCircular(CNode* head) {
    if (!head) return 0;

    int count = 1;
    CNode* cur = head->next;

    while (cur != head) {
        count++;
        cur = cur->next;
    }
    return count;
}

int main() {

    /*---------------------------------
        Example Doubly Linked List
        10 <-> 20 <-> 30 <-> 40
    ----------------------------------*/
    DNode* d1 = new DNode(10);
    d1->next = new DNode(20); d1->next->prev = d1;
    d1->next->next = new DNode(30); d1->next->next->prev = d1->next;
    d1->next->next->next = new DNode(40); d1->next->next->next->prev = d1->next->next;

    cout << "Size of Doubly Linked List = " << sizeOfDoubly(d1) << endl;

    /*---------------------------------
        Example Circular Linked List
        5 → 15 → 25 → 35 → back to 5
    ----------------------------------*/
    CNode* c1 = new CNode(5);
    c1->next = new CNode(15);
    c1->next->next = new CNode(25);
    c1->next->next->next = new CNode(35);
    c1->next->next->next->next = c1; // make circular

    cout << "Size of Circular Linked List = " << sizeOfCircular(c1) << endl;

    return 0;
}
