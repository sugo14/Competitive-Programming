#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = {x, i + 1};
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    int left = 0, right = n - 1;
    while (left < right) {
        pair<int, int> l = v[left], r = v[right];
        if (l.first + r.first == t) {
            cout << l.second << ' ' << r.second << endl;
            return 0;
        }
        if (l.first + r.first < t) {
            left++;
        }
        else {
            right--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
