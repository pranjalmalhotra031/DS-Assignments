// There are different ways to look at a binary tree. The right view of a binary tree contains 
// the set of nodes that will be visible if you look at the binary tree from the right side. Given 
// the root node of a binary tree, return an array containing the node elements in the right view, 
// from top to bottom.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

// Build a binary tree from level-order array where -1 = NULL
TreeNode* build_from_level_order(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || arr[0] == -1) return nullptr;

    vector<TreeNode*> nodes(n, nullptr);
    for (int i = 0; i < n; ++i)
        if (arr[i] != -1) nodes[i] = new TreeNode(arr[i]);

    for (int i = 0; i < n; ++i) {
        if (!nodes[i]) continue;
        int left = 2*i + 1, right = 2*i + 2;
        if (left < n)  nodes[i]->left  = nodes[left];
        if (right < n) nodes[i]->right = nodes[right];
    }
    return nodes[0];
}

// Right View — BFS: last node of each level
vector<int> rightView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        TreeNode* node = nullptr;

        // traverse current level
        for (int i = 0; i < levelSize; ++i) {
            node = q.front();
            q.pop();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // last node in this level = rightmost
        result.push_back(node->val);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    TreeNode* root = build_from_level_order(arr);

    vector<int> ans = rightView(root);
    for (int x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}
