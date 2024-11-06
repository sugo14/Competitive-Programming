#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    ll x = n * (n + 1) / 2;
    if (x % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    ll y = x / 2;
    vector<ll> used;
    set<ll> used2;
    ll big = n;
    while (y > 0) {
        ll a = min((ll) big, y);
        used.push_back(a);
        used2.insert(a);
        y -= a;
        big--;
    }
    cout << "YES" << '\n' << used.size() << '\n';
    for (ll i = 0; i < used.size(); i++) {
        cout << used[i];
        if (i != used.size() - 1) {
            cout << " ";
        }
    }
    cout << '\n' << n - used.size() << '\n';
    for (ll i = 1; i <= n; i++) {
        if (used2.find(i) == used2.end()) {
            cout << i;
            if (i != n) {
                cout << " ";
            }
        }
    }
    cout << endl;
    return 0;
}
