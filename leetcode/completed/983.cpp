#include <bits/stdc++.h>
using namespace std;

// heheheha

class Solution {
    int dp[401], travel[401];
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for (int i = 0; i < days.size(); i++) { travel[days[i]] = 1; }
        for (int i = 1; i <= 400; i++) {
            dp[i] = min((travel[i] == 0) ? dp[i - 1] : (dp[i - 1] + costs[0]), min((i - 7 >= 0 ? (dp[i - 7] + costs[1]) : INT_MAX), (i - 30 >= 0 ? (dp[i - 30] + costs[2]) : INT_MAX)));
        }
        return dp[400];
    }
};
