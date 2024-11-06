#include <bits/stdc++.h>
using namespace std;

// actually pretty beautiful sol if i do say so myself

int n, i1, i2;
int v1[300001], v2[300001];
vector<pair<int, int>> l, r;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> v1[i]; }
    for (int i = 0; i < n; i++) { cin >> v2[i]; }
    while (i1 < n && i2 < n) {
        if (i2 < i1) { l.push_back({i2, i1}); }
        while (v1[i1] == v2[i2] && i2 < n) { i2++; }
        if (i1 < i2 - 1) { r.push_back({i1, i2 - 1}); }
        i1++;
    }
    if (i2 != n) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl << r.size() + l.size() << endl;
    for (int i = 0; i < l.size(); i++) { cout << "L " << l[i].first << ' ' << l[i].second << endl; }
    reverse(r.begin(), r.end());
    for (int i = 0; i < r.size(); i++) { cout << "R " << r[i].first << ' ' << r[i].second << endl; }
}
