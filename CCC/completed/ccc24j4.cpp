#include <bits/stdc++.h>
using namespace std;

// this is the good way to do this i think

string stringWOChar(string s, char c) {
    string newS = "";
    for (char ch : s) {
        if (ch != c) {
            newS += ch;
        }
    }
    return newS;
}

pair<char, char> difference(string s1, string s2) {
    pair<char, char> diff = {'\0', '\0'};
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            if (diff != make_pair('\0', '\0') && diff != make_pair(s1[i], s2[i])) {
                return {'\0', '\0'};
            }
            diff = {s1[i], s2[i]};
        }
    }
    return diff;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() == s2.size()) {
        pair<char, char> diff = difference(s1, s2);
        cout << diff.first << ' ' << diff.second << '\n';
        cout << '-' << endl;
        return 0;
    }
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        string newS1 = stringWOChar(s1, c);
        pair<char, char> diff = difference(newS1, s2);
        if (diff != make_pair('\0', '\0')) {
            cout << diff.first << ' ' << diff.second << '\n';
            cout << c << endl;
            return 0;
        }
    }
}
