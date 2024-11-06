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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> thing;
        thing.push(root);
        int sum = 0;
        while (!thing.empty()) {
            auto next = thing.front();
            thing.pop();
            if (next == nullptr) { continue; }
            if (next->left != nullptr && next->left->left == nullptr && next->left->right == nullptr) {
                sum += next->left->val;
            }
            thing.push(next->left);
            thing.push(next->right);
        }
        return sum;
    }
};
