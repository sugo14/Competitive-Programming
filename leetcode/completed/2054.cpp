#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans = 0;
        for (int i = 0; i < events.size(); i++) { ans = max(ans, events[i][2]); }

        map<int, int> maxAfter;
        int bigCurr = 0;
        sort(events.begin(), events.end());
        for (int i = events.size() - 1; i >= 0; i--) {
            bigCurr = max(bigCurr, events[i][2]);
            maxAfter[events[i][0]] = bigCurr;
        }

        for (int i = 0; i < events.size(); i++) {
            auto it = maxAfter.upper_bound(events[i][1]);
            if (it != maxAfter.end()) {
                ans = max(ans, events[i][2] + it->second);
            }
        }

        return ans;
    }
};
