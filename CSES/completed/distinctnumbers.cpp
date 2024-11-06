#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    set<int> seen;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (seen.find(x) == seen.end()) {
            seen.insert(x);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
