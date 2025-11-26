//  Given a binary tree, return its maximum depth. The depth of a binary tree is the number 
// of nodes from the root node to any of the leaf nodes. The maximum depth is the maximum of 
// the depths across all the paths.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

// Build from level-order array where -1 indicates NULL.
TreeNode* build_from_level_order(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || arr[0] == -1) return nullptr;
    vector<TreeNode*> nodes(n, nullptr);
    for (int i = 0; i < n; ++i) if (arr[i] != -1) nodes[i] = new TreeNode(arr[i]);
    for (int i = 0; i < n; ++i) {
        if (!nodes[i]) continue;
        int l = 2*i + 1, r = 2*i + 2;
        if (l < n) nodes[i]->left  = nodes[l];
        if (r < n) nodes[i]->right = nodes[r];
    }
    return nodes[0];
}

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    TreeNode* root = build_from_level_order(arr);
    cout << maxDepth(root) << '\n';
    return 0;
}
