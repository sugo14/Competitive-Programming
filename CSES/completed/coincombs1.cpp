#include <bits/stdc++.h>
using namespace std;

int coins[101];
int dp[1000001];

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(NULL); std::cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        dp[coins[i]] = 1;
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] < 0) { continue; }
            dp[i] += dp[i - coins[j]];
            dp[i] %= 1000000007;
        }
    }
    cout << dp[x] << "\n";
    return 0;
}
