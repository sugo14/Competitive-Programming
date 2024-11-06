#include <bits/stdc++.h>
using namespace std;

int n, m;
multiset<int> s;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto y = s.upper_bound(x);
        if (y == s.begin()) {
            cout << "-1" << endl;
            continue;
        }
        y--;
        cout << *y << endl;
        s.erase(y);
    }
    return 0;
}
