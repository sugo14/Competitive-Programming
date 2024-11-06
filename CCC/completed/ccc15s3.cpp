#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main() {
    int g, p;
    cin >> g >> p;
    for (int i = 0; i < g; i++) { s.insert(i + 1); }
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        auto best = s.upper_bound(x);
        if (best == s.begin()) {
            cout << i << endl;
            return 0;
        }
        best--;
        if (*best > x) {
            cout << i << endl;
            return 0;
        }
        s.erase(best);
    }
    cout << p << endl;
    return 0;
}
