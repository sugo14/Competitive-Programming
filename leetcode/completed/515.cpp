#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) { return {}; }
        vector<TreeNode*> curr = {root};
        vector<int> ans;
        while (!curr.empty()) {
            vector<TreeNode*> next;
            int max_val = INT_MIN;
            for (auto node : curr) {
                max_val = max(max_val, node->val);
                if (node->left) { next.push_back(node->left); }
                if (node->right) { next.push_back(node->right); }
            }
            ans.push_back(max_val);
            curr = next;
        }
        return ans;
    }
};