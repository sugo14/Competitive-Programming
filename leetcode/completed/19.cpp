#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int x = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            x++;
        }
        x -= n;
        curr = head;
        for (int i = 0; i < x; i++) {
            curr = curr->next;
        }
        if (head) {
            head->next = head->next->next;
        }
        return head;
    }
};
