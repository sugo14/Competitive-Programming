#include <bits/stdc++.h>
using namespace std;

int coins[101];
bool dp[101][100001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> coins[i]; }
    dp[0][coins[0]] = 1;
    for (int i = 1; i < n; i++) {
        dp[i][coins[i]] = 1;
        for (int j = 1; j <= 100000; j++) {
            dp[i][j] = dp[i][j] || dp[i - 1][j];
            if (j - coins[i] >= 0) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - coins[i]];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100000; i++) { ans += dp[n - 1][i]; }
    cout << ans << endl;
    for (int i = 0; i <= 100000; i++) {
        if (dp[n - 1][i]) { cout << i << " "; }
    }
}
