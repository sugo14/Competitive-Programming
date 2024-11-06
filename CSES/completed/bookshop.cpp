#include <bits/stdc++.h>
using namespace std;

pair<int, int> books[1001];
int dp[100001];
bitset<1001> state[100001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) { cin >> books[i].first; }
    for (int i = 0; i < n; i++) { cin >> books[i].second; }
    for (int i = 1; i <= x; i++) {
        dp[i] = dp[i - 1];
        state[i] = state[i - 1];
        for (int j = 0; j < n; j++) {
            if (i < books[j].first) { continue; }
            if (state[i - books[j].first][j]) { continue; }
            int x = dp[i - books[j].first] + books[j].second;
            if (x > dp[i]) {
                dp[i] = x;
                state[i] = state[i - books[j].first];
                state[i][j] = true;
            }
        }
        dp[i] %= 1000000007;
    }
    cout << dp[x] << endl;
    return 0;
}
