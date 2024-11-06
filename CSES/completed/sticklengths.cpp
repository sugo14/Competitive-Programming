#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    vector<ll> nums;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    ll median = nums[n / 2];
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += std::abs(nums[i] - median);
    }
    cout << ans << endl;
    return 0;
}
