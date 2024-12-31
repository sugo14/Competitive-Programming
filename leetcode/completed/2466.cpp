#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long dp[100001];
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        for (int i = 1; i <= high; i++) { dp[i] = ((i - zero >= 0 ? dp[i - zero] : 0) + (i - one >= 0 ? dp[i - one] : 0) + (i == zero) + (i == one)) % 1000000007; }
        return accumulate(dp + low, dp + high + 1, 0, [](long long a, long long b) { return (a + b) % 1000000007; });
    }
};
