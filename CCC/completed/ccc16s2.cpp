#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long i, n;
    cin >> i >> n;
    vector<long long> a(n), b(n);
    for (long long j = 0; j < n; j++) { cin >> a[j]; }
    for (long long j = 0; j < n; j++) { cin >> b[j]; }
    long long ans = 0;
    if (i == 1) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (long long j = 0; j < n; j++) { ans += max(a[j], b[j]); }
    }
    else if (i == 2) {
        a.insert(a.end(), b.begin(), b.end());
        sort(a.begin(), a.end(), greater<long long>());
        for (long long j = 0; j < n; j++) {
            ans += a[j];
        }
    }
    cout << ans << endl;
    return 0;
}
