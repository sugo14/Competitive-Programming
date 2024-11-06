#include <bits/stdc++.h>
using namespace std;

int prices[1001];
int pages[1001];
int dp[1001][100001];
int n, x;

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(NULL); std::cout.tie(NULL);
    cin >> n >> x;
    for (int i = 0; i < n; i++) { cin >> prices[i]; }
    for (int i = 0; i < n; i++) { cin >> pages[i]; }
    for (int j = prices[0]; j <= x; j++) { dp[0][j] = pages[0]; }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= prices[i]) { dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i]] + pages[i]); }
        }
    }
    cout << dp[n - 1][x] << endl;
    return 0;
}
