#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int n;
long long dp[1000001];

long long solve() {
    dp[0] = 1;
    for (int r = 1; r <= n; r++) {
        long long ans = 0;
        for (int i = 0; i < min(r, 6); i++) {
            ans += dp[r - i - 1];
            ans %= MOD;
        }
        dp[r] = ans;
    }
    return dp[n];
}

int main() {
    cin >> n;
    cout << solve() << endl;
    return 0;
}
