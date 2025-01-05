#include <bits/stdc++.h>
using namespace std;

int toInt(char c) {
    return c - '0';
}

int main() {
    string s, ans;
    cin >> s >> s;
    for (int i = 0; i < s.size(); i++) {
        if (i == s.size() - 1 || toInt(s[i + 1]) <= toInt(s[i])) {
            ans.push_back(s[i]);
            continue;
        }
        ans.push_back(s[i + 1]);
        ans.push_back(s[i]);
        ans.insert(ans.end(), s.begin() + i + 2, s.end());
        break;
    }
    cout << ans << endl;
}
