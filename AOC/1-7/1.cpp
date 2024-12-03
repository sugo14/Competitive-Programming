#include <bits/stdc++.h>
using namespace std;

int cnt[1000005];

int main() {
    freopen("1.in", "r", stdin);
    vector<int> v1, v2;
    for (int i = 0; i < 1000; i++) {
        int x, y;
        cin >> x >> y;
        v1.push_back(x);
        v2.push_back(y);
        cnt[y]++;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        ans += cnt[v1[i]] * v1[i];
    }
    cout << ans << endl;
}