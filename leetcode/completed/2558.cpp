#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long ans = 0;
        for (auto& x : gifts) {
            ans += x;
            pq.push(x);
        }
        for (int i = 0; i < k; i++) {
            int x = pq.top(), y = sqrt(x);
            ans += y - x;
            pq.push(y);
            pq.pop();
        }
        return ans;
    }
};
