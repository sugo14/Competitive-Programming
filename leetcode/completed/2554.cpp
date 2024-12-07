#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban;
        for (auto& x : banned) { ban.insert(x); }
        int ans = 0, currCnt = 0;
        for (int i = 1; i <= n; i++) {
            if (currCnt + i > maxSum) { break; }
            if (ban.find(i) == ban.end()) {
                currCnt += i;
                ans++;
            }
        }
        return ans;
    }
};
