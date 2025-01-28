#include <bits/stdc++.h>
using namespace std;

int n, a, memo[1000001];
stack<int> ones;
long long ans = 0;

int largestPrimeFactor(int x) {
    int originalX = x;
    if (memo[x] != 0) { return memo[x]; }
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            x /= i;
            memo[originalX] = i;
        }
    }
    memo[originalX] = max(x, memo[originalX]);
    return memo[originalX];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        a = largestPrimeFactor(a);
        if (a == 1) { ones.push(i); }
        while (ones.size() > 0 && a > (i - ones.top() + 1)) { ones.pop(); }
        ans += ones.size();
    }
    cout << ans << '\n';
    return 0;
}
