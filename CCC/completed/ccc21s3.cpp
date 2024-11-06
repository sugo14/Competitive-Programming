#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[200001][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll upper = 0, lower = LLONG_MAX;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        upper = max(upper, arr[i][0]);
        lower = min(lower, arr[i][0]);
    }
    while (upper - lower > 2) {
        ll mid1 = lower + (upper - lower) / 3;
        ll mid2 = upper - (upper - lower) / 3;
        ll cost1 = 0, cost2 = 0;
        for (ll i = 0; i < n; i++) { cost1 += max(abs(arr[i][0] - mid1) - arr[i][2], 0LL) * arr[i][1]; }
        for (ll i = 0; i < n; i++) { cost2 += max(abs(arr[i][0] - mid2) - arr[i][2], 0LL) * arr[i][1]; }
        if (cost1 < cost2) { upper = mid2; }
        else { lower = mid1; }
    }
    ll ans = LLONG_MAX;
    for (ll i = lower; i <= upper; i++) {
        ll newAns = 0;
        for (ll j = 0; j < n; j++) { newAns += max(abs(arr[j][0] - i) - arr[j][2], 0LL) * arr[j][1]; }
        ans = min(ans, newAns);
    }
    cout << ans << endl;
    return 0;
}
