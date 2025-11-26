// Given in-order and post-order traversals, write a program to construct the Binary Tree. 

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Recursive builder
// post: postorder vector
// inIndex: map value -> index in inorder
// postIndex: reference to current index in postorder (starts at n-1 and moves left)
// inStart..inEnd: current inorder bounds
Node* buildRec(const vector<int>& post, unordered_map<int,int>& inIndex,
               int& postIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return nullptr;

    // root is current postorder element
    int rootVal = post[postIndex--];
    Node* root = new Node(rootVal);

    // if leaf node
    if (inStart == inEnd) return root;

    // find index of root in inorder to split left/right
    int idx = inIndex[rootVal];

    // build right subtree first because we are consuming postorder from the end
    root->right = buildRec(post, inIndex, postIndex, idx + 1, inEnd);
    root->left  = buildRec(post, inIndex, postIndex, inStart, idx - 1);

    return root;
}

Node* buildTreeFromInPost(const vector<int>& inorder, const vector<int>& postorder) {
    int n = inorder.size();
    if (n == 0) return nullptr;
    unordered_map<int,int> inIndex;
    inIndex.reserve(n * 2);
    for (int i = 0; i < n; ++i) inIndex[inorder[i]] = i;
    int postIndex = n - 1;
    return buildRec(postorder, inIndex, postIndex, 0, n - 1);
}

// traversals for verification
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
void printPreorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// free tree
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

    vector<int> inorder(n), postorder(n);
    cout << "Enter inorder (" << n << " values):\n";
    for (int i = 0; i < n; ++i) cin >> inorder[i];

    cout << "Enter postorder (" << n << " values):\n";
    for (int i = 0; i < n; ++i) cin >> postorder[i];

    Node* root = buildTreeFromInPost(inorder, postorder);

    cout << "Constructed tree (preorder): ";
    printPreorder(root);
    cout << "\nConstructed tree (inorder) : ";
    printInorder(root);
    cout << "\n";

    freeTree(root);
    return 0;
}
