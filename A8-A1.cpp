// Given the root of a binary tree, return the sum of all left leaves. A leaf is a node with no 
// children. A left leaf is a leaf that is the left child of another node. 
// Example:  
// Input: root = [3,9,20,null,null,15,7] 
// Output: 24 
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively. 

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

// Build tree from level-order array where -1 indicates NULL.
// Positions -> treated as a complete-binary-tree indexing.
TreeNode* build_from_level_order(const vector<int>& arr) {
    int n = arr.size();
    if (n==0 || arr[0]==-1) return nullptr;
    vector<TreeNode*> nodes(n, nullptr);
    for (int i = 0; i < n; ++i) {
        if (arr[i] != -1) nodes[i] = new TreeNode(arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (!nodes[i]) continue;
        int l = 2*i + 1, r = 2*i + 2;
        if (l < n) nodes[i]->left = nodes[l];
        if (r < n) nodes[i]->right = nodes[r];
    }
    return nodes[0];
}

int dfs_sum_left(TreeNode* node, bool isLeft) {
    if (!node) return 0;
    if (!node->left && !node->right) return isLeft ? node->val : 0;
    return dfs_sum_left(node->left, true) + dfs_sum_left(node->right, false);
}

int sumOfLeftLeaves(TreeNode* root) {
    return dfs_sum_left(root, false);
}

// driver: reads n then n integers (level order with -1) and prints sum
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    TreeNode* root = build_from_level_order(arr);
    cout << sumOfLeftLeaves(root) << "\n";
    return 0;
}
