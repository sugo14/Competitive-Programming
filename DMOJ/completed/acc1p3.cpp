#include <bits/stdc++.h>
using namespace std;

int arr1[1000001], arr2[1000001];
string a, b;
int n;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) { arr1[i] = (a[i] == b[i]) + (i > 0 ? arr1[i - 1] : 0); }
    for (int i = n - 1; i >= 0; i--) { arr2[i] = (a[i] == b[i - 1]) + (i < n - 1 ? arr2[i + 1] : 0); }
    int ans = 0;
    for (int i = 0; i < n; i++) { ans = max(ans, (i > 0 ? arr1[i - 1] : 0) + (i < n - 1 ? arr2[i + 1] : 0)); }
    cout << ans << endl;
}
