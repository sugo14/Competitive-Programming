#include <bits/stdc++.h>
using namespace std;

int thing[200001];

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> thing[i];
    }
    sort(thing, thing + n);
    int l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        if (thing[l] + thing[r] <= x) {
            l++;
        }
        r--;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
