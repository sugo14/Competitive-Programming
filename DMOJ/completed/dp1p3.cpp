#include <bits/stdc++.h>
using namespace std;

int arr[5005], dp[5005];

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(NULL); std::cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) { dp[i] = max(dp[i], dp[j] + 1); }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
