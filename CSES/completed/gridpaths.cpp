#include <bits/stdc++.h>
using namespace std;

string grid[1001];
int dp[1001][1001];
int n;

int access(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= n) { return 0; }
    return dp[i][j];
}

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(NULL); std::cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
        cout << 0 << endl;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) { continue; }
            if (grid[i][j] == '*') { continue; }
            dp[i][j] = access(i, j - 1) + access(i - 1, j);
            dp[i][j] %= 1000000007;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}
