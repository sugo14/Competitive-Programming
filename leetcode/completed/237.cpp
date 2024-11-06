#include <bits/stdc++.h>

// actual dumbest problem ive seen in my life

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) { *node = *(node->next); }
};
