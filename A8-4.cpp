// Write a program to determine whether a given binary tree is a BST or not.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

// ----------------------
// Method 1: Range check (min/max)
// Enforces min < node->data < max (strict).
// Use long long limits to avoid overflow for extreme values.
// ----------------------
bool isBSTRange(Node* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if (!(node->data > minVal && node->data < maxVal)) return false;
    return isBSTRange(node->left, minVal, node->data) &&
           isBSTRange(node->right, node->data, maxVal);
}

bool isBSTRange(Node* root) {
    return isBSTRange(root, LLONG_MIN, LLONG_MAX);
}

// ----------------------
// Method 2: Inorder traversal check
// Inorder of BST (strict) must be strictly increasing.
// keep previous node value during traversal.
// ----------------------
bool inorderCheck(Node* node, long long &prev) {
    if (!node) return true;
    if (!inorderCheck(node->left, prev)) return false;
    if (!(node->data > prev)) return false; // strict: >
    prev = node->data;
    return inorderCheck(node->right, prev);
}

bool isBSTInorder(Node* root) {
    long long prev = LLONG_MIN;
    return inorderCheck(root, prev);
}

// ----------------------
// Helpers to build sample trees and free memory
// ----------------------
Node* sampleBST() {
    // Construct a valid BST:
    //        20
    //       /  \
    //     10    30
    //     / \     \
    //    5  15    40
    Node* r = new Node(20);
    r->left = new Node(10);
    r->right = new Node(30);
    r->left->left = new Node(5);
    r->left->right = new Node(15);
    r->right->right = new Node(40);
    return r;
}

Node* sampleNonBST() {
    // A tree that is not BST:
    //       20
    //      /  \
    //    30    10   <-- children violate BST property
    Node* r = new Node(20);
    r->left = new Node(30);
    r->right = new Node(10);
    return r;
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    // Test 1: valid BST
    Node* bst = sampleBST();
    cout << "Sample BST (range method): " << (isBSTRange(bst) ? "YES" : "NO") << "\n";
    cout << "Sample BST (inorder method): " << (isBSTInorder(bst) ? "YES" : "NO") << "\n\n";

    // Test 2: not a BST
    Node* nonbst = sampleNonBST();
    cout << "Sample non-BST (range method): " << (isBSTRange(nonbst) ? "YES" : "NO") << "\n";
    cout << "Sample non-BST (inorder method): " << (isBSTInorder(nonbst) ? "YES" : "NO") << "\n\n";

    freeTree(bst);
    freeTree(nonbst);
    return 0;
}
