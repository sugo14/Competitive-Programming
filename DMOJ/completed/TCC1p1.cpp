#include <bits/stdc++.h>
using namespace std;

int n, y = 0;
string s;

int main() {
    cin >> n >> s;
    for (char c : s) {
        if (c == 'Y') {
            y++;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (y * 2 > n) {
            cout << "YES" << endl;
            return 0;
        }
        if (s[i] == 'Y') {
            continue;
        }
        if (y > i) {
            y++;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
