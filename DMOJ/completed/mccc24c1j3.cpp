#include <bits/stdc++.h>
using namespace std;

int r[1000001], b[1000001];

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'G') {
            r[i] = 0;
            continue;
        }
        if (i > 0) {
            r[i] = r[i - 1];
        }
        if (s[i] == 'R') {
            r[i]++;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'G') {
            b[i] = 0;
            continue;
        }
        if (i < s.size() - 1) {
            b[i] = b[i + 1];
        }
        if (s[i] == 'B') {
            b[i]++;
        }
    }
    long long ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'G') {
            if (i > 0 && i < s.size() - 1) {
                ans += (long long) r[i - 1] * (long long) b[i + 1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
