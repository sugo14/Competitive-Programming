#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    ll ans = 2;
    for (int i = 1; i < n; i++) {
        ans = (ans * 2) % MOD;
    }
    cout << ans << endl;
}
