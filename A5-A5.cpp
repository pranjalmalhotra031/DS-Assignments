//  Given two polynomial numbers represented by two linked lists. The task is 
// to add these lists (meaning the coefficients with the same variable powers will be 
// added). 

#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) : coeff(c), pow(p), next(nullptr) {}
};

// Insert a term in descending order of powers
void insertTerm(Node*& head, int coeff, int pow) {
    Node* newNode = new Node(coeff, pow);
    if (!head || pow > head->pow) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* cur = head;
    Node* prev = nullptr;
    while (cur && cur->pow >= pow) {
        if (cur->pow == pow) {
            // If power already exists, add coefficients
            cur->coeff += coeff;
            delete newNode;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    // insert between prev and cur
    prev->next = newNode;
    newNode->next = cur;
}

// Display polynomial in readable form
void printPoly(Node* head) {
    if (!head) {
        cout << "0\n";
        return;
    }
    Node* cur = head;
    bool first = true;
    while (cur) {
        if (cur->coeff != 0) {
            if (!first && cur->coeff > 0) cout << " + ";
            if (cur->pow == 0) {
                cout << cur->coeff;
            } else if (cur->pow == 1) {
                if (cur->coeff == 1) cout << "x";
                else if (cur->coeff == -1) cout << "-x";
                else cout << cur->coeff << "x";
            } else {
                if (cur->coeff == 1) cout << "x^" << cur->pow;
                else if (cur->coeff == -1) cout << "-x^" << cur->pow;
                else cout << cur->coeff << "x^" << cur->pow;
            }
            first = false;
        }
        cur = cur->next;
    }
    if (first) cout << "0"; // all coeffs were zero
    cout << "\n";
}

// Add two polynomials (both sorted in descending pow) and return head of result
Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = nullptr;
    Node** lastPtr = &result; // pointer to last->next (for easy append)

    while (p1 && p2) {
        if (p1->pow == p2->pow) {
            int summed = p1->coeff + p2->coeff;
            if (summed != 0) {
                *lastPtr = new Node(summed, p1->pow);
                lastPtr = &((*lastPtr)->next);
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            *lastPtr = new Node(p1->coeff, p1->pow);
            lastPtr = &((*lastPtr)->next);
            p1 = p1->next;
        } else { // p2->pow > p1->pow
            *lastPtr = new Node(p2->coeff, p2->pow);
            lastPtr = &((*lastPtr)->next);
            p2 = p2->next;
        }
    }

    // append remaining terms
    while (p1) {
        *lastPtr = new Node(p1->coeff, p1->pow);
        lastPtr = &((*lastPtr)->next);
        p1 = p1->next;
    }
    while (p2) {
        *lastPtr = new Node(p2->coeff, p2->pow);
        lastPtr = &((*lastPtr)->next);
        p2 = p2->next;
    }

    return result;
}

// Free a polynomial list
void freePoly(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    // Example:
    // Poly1: 5x^3 + 4x^2 + 2   (represented as nodes in descending power)
    // Poly2: 5x^2 + 5x + 5
    Node* poly1 = nullptr;
    insertTerm(poly1, 5, 3);
    insertTerm(poly1, 4, 2);
    insertTerm(poly1, 2, 0);

    Node* poly2 = nullptr;
    insertTerm(poly2, 5, 2);
    insertTerm(poly2, 5, 1);
    insertTerm(poly2, 5, 0);

    cout << "Polynomial 1: ";
    printPoly(poly1);
    cout << "Polynomial 2: ";
    printPoly(poly2);

    Node* sum = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    printPoly(sum);

    freePoly(poly1);
    freePoly(poly2);
    freePoly(sum);
    return 0;
}
