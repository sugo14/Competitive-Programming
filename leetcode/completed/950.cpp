#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int i = 0;
        vector<int> ans(deck.size());
        queue<int> q;
        for (int j = 0; j < deck.size(); j++) {
            q.push(j);
        }
        while (!q.empty()) {
            ans[q.front()] = deck[i];
            i++;
            q.pop();
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};
