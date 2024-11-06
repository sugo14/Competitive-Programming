#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!s.empty() && *s.rbegin() > x) {
            s.erase(s.upper_bound(x));
        }
        s.insert(x);
    }
    cout << s.size() << endl;
    return 0;
}
