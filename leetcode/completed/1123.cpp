#include <bits/stdc++.h>
using namespace std;

// i believe this is a bit overcomplicated but its O(n) so idc
// basically, identify the deepest leaves, and then do a dfs to find the number of 
// deepest leaves that are children of each node
// then, find the deepest node that has the maximum number of deepest leaf children

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int depths[1001] = {0};
    int lcaCnt[1001] = {0};
    TreeNode* nodeWithVal[1001] = {nullptr};
    int maxDepth = 0;

    int dfs(TreeNode* node) {
        if (depths[node->val] == maxDepth) lcaCnt[node->val] += 1;
        if (node->left) lcaCnt[node->val] += dfs(node->left);
        if (node->right) lcaCnt[node->val] += dfs(node->right);
        return lcaCnt[node->val];
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> curr = {root};
        while (!curr.empty()) {
            vector<TreeNode*> next;
            for (auto node : curr) {
                depths[node->val] = maxDepth;
                nodeWithVal[node->val] = node;
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            if (next.empty()) break;
            maxDepth++;
            curr = next;
        }

        dfs(root);
        int maxDepth = -1;
        TreeNode* lca = nullptr;
        for (int i = 0; i < 1001; i++) {
            if (nodeWithVal[i] && depths[i] > maxDepth && lcaCnt[i] == curr.size()) {
                maxDepth = depths[i];
                lca = nodeWithVal[i];
            }
        }
        return lca;
    }
};
