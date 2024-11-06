#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    while (n > 0) {
        int big = 0;
        for (int i = 1; i <= n; i *= 10) {
            big = max(big, (n / i) % 10);
        }
        n -= big;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
