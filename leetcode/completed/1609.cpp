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
    bool isEvenOddTree(TreeNode* root) {
        vector<TreeNode*> curr = {root};
        int index = 0;
        while (!curr.empty()) {
            vector<TreeNode*> next;
            int prev = index % 2 == 0 ? INT_MIN : INT_MAX;
            for (auto node : curr) {
                if (index % 2 == 0) { // even: odd vals, strict increasing order
                    if (node->val % 2 == 0 || node->val >= prev) {
                        return false;
                    }
                }
                else { // odd: even vals, strict decreasing order
                    if (node->val % 2 == 1 || node->val <= prev) {
                        return false;
                    }
                }
                prev = node->val;
                if (node == nullptr) { continue; }
                next.push_back(node->left);
                next.push_back(node->right);
            }
            curr = next;
            index++;
        }
        return true;
    }
};
