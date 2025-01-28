#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

char ac(int i) {
    if (i < 0 || i >= n) { return '0'; }
    return s[i];
}

int main() {
    cin >> n >> k >> s;
    
    bool good = (s == string(n, '0')) || (k > 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && ac(i - 1) != ac(i + 1)) { good = true; }
        else if (s[i] == '1' && ac(i - 1) == ac(i + 1)) { good = true; }
        if (good) { break; }
    }
    if (!good) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> lens;
    int len = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (len > 0) { lens.push_back(len); }
            len = 0;
        }
        else { len++; }
    }
    if (len > 0) { lens.push_back(len); }

    int ans = 0;
    for (auto& x : lens) { ans += x + ((x % 2 == 0) ? 2 : 0); }

    int evenCount = 0;
    for (auto& x : lens) { evenCount += (x % 2 == 0); }
    ans -= min(evenCount, k) * 3;
    k -= min(evenCount, k);
    ans -= k;

    cout << max(0, ans) << '\n';
    return 0;
}
