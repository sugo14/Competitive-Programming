#include <bits/stdc++.h>
using namespace std;

const int KEYS = 8;

class Solution {
public:
    int minimumPushes(string word) {
        cin.tie(0)->sync_with_stdio(0);
        int occ[26] = {0};
        for (int i = 0; i < word.size(); i++) { occ[word[i] - 'a']++; }
        priority_queue<int> q;
        for (int i = 0; i < 26; i++) { q.push(occ[i]); }
        int ans = 0, keysUsed = 0;
        while (!q.empty()) {
            ans += q.top() * (keysUsed / KEYS + 1);
            q.pop();
            keysUsed++;
        }
        return ans;
    }
};