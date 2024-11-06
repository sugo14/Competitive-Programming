#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, _;
    cin >> n >> _;
    for (int i = 0; i < n; i++) {
        string s;
        int freqMap[26];
        fill(freqMap, freqMap + 26, 0);
        cin >> s;
        for (char c : s) {
            freqMap[c - 'a']++;
        }
        bool light = (freqMap[s[0] - 'a'] == 1);
        bool flag = false;
        for (int i = 1; i < s.size(); i++) {
            bool light2 = freqMap[s[i] - 'a'] == 1;
            if (light == light2) {
                cout << "F" << endl;
                flag = true;
                break;
            }
            light = light2;
        }
        if (!flag) {
            cout << "T" << endl;
        }
    }
    return 0;
}
