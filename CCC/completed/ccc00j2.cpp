#include <bits/stdc++.h>
using namespace std;

bool isSameWhenRotated(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        char c = s[i];
        if (!(c == '1' || c == '6' || c == '8' || c == '9' || c == '0')) {
            return false;
        }
        if (c == '6') {
            if (s[s.size() - 1 - i] != '9') {
                return false;
            }
        }
        else if (c == '9') {
            if (s[s.size() - 1 - i] != '6') {
                return false;
            }
        }
        else {
            if (s[s.size() - 1 - i] != c) {
                return false;
            }
        }
    }
    if ((s.size() % 2 == 1)) {
        char c = s[s.size() / 2];
        if (!(c == '1' || c == '8' || c == '0')) {
            return false;
        }
    }
    return true;
}

int solve(int lower, int upper) {
    int ans = 0;
    for (int i = lower; i <= upper; i++) {
        if (isSameWhenRotated(to_string(i))) {
            ans++;
        }
    }
    return ans;
}

int m, n;

int main() {
    cin >> m >> n;
    cout << solve(m, n) << endl;
    return 0;
}
