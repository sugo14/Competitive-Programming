#include <bits/stdc++.h>
using namespace std;

vector<string> curr, nex;
set<string> vis;

void fix(string& s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') { cnt++; }
        else {
            if (cnt >= 4) {
                for (int j = i - cnt; j < i; j++) { s[j] = '0'; }
            }
            cnt = 0;
        }
    }
    if (cnt >= 4) {
        for (int j = s.size() - cnt; j < s.size(); j++) { s[j] = '0'; }
    }
}

int main() {
    int n;
    cin >> n;
    string s(n, ' '), sol(n, '0');
    for (int i = 0; i < n; i++) { cin >> s[i]; }
    curr.push_back(s);
    int ans = 1;
    while (true) {
        nex.clear();
        for (string& x : curr) {
            for (int i = 1; i < n - 1; i++) {
                if (x[i - 1] == '1' || x[i + 1] == '1') {
                    string newX = x;
                    newX[i] = '1';
                    fix(newX);
                    if (vis.find(newX) == vis.end()) {
                        vis.insert(newX);
                        nex.push_back(newX);
                    }
                    if (newX == sol) {
                        cout << ans << endl;
                        return 0;
                    }
                }
                else { s[i] = '0'; }
            }
        }
        curr = nex;
        ans++;
    }
}
