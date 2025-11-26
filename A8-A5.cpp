//Given preorder and in-order traversals, write a program to construct the Binary Tree.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Recursive helper to build tree
// pre: preorder vector
// inIndex: map from value -> index in inorder
// preIndex: reference to current index in preorder
// inStart..inEnd: current inorder subarray bounds
Node* buildRec(const vector<int>& pre, unordered_map<int,int>& inIndex,
               int& preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return nullptr;

    // Root value from current preorder index
    int rootVal = pre[preIndex++];
    Node* root = new Node(rootVal);

    // If this node has no children
    if (inStart == inEnd) return root;

    // Find root position in inorder to split left and right
    int idx = inIndex[rootVal];

    // Build left and right subtrees
    root->left  = buildRec(pre, inIndex, preIndex, inStart, idx - 1);
    root->right = buildRec(pre, inIndex, preIndex, idx + 1, inEnd);

    return root;
}

Node* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    int n = preorder.size();
    if (n == 0) return nullptr;
    unordered_map<int,int> inIndex;
    inIndex.reserve(n * 2);
    for (int i = 0; i < n; ++i) inIndex[inorder[i]] = i;
    int preIndex = 0;
    return buildRec(preorder, inIndex, preIndex, 0, n - 1);
}

// print inorder (should match input inorder)
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// print preorder (should match input preorder)
void printPreorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    if (!(cin >> n)) return 0;

    vector<int> preorder(n), inorder(n);
    cout << "Enter preorder (" << n << " values):\n";
    for (int i = 0; i < n; ++i) cin >> preorder[i];

    cout << "Enter inorder (" << n << " values):\n";
    for (int i = 0; i < n; ++i) cin >> inorder[i];

    // Build
    Node* root = buildTree(preorder, inorder);

    cout << "Constructed tree inorder: ";
    printInorder(root);
    cout << "\nConstructed tree preorder: ";
    printPreorder(root);
    cout << "\n";

    freeTree(root);
    return 0;
}
