#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
int coins[101];
int n, x;

/* int solve(int a) {
    if (a == 0) { return 0; }
    int small = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a - coins[i] < 0) { break; }
        small = min(small, solve(a - coins[i]) + 1);
    }
    return small;
} */

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(NULL); std::cout.tie(NULL);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins, coins + n);
    for (int i = 1; i <= x; i++) {
        if (i < coins[0]) { continue; }
        int small = INT_MAX;
        for (int j = 0; j < n && coins[j] <= i; j++) {
            if (i - coins[j] > 0 && dp[i - coins[j]] == 0) { continue; }
            small = min(small, dp[i - coins[j]] + 1);
        }
        dp[i] = (small == INT_MAX) ? 0 : small;
    }
    cout << ((dp[x] == 0) ? -1 : dp[x]) << "\n";
    return 0;
}
