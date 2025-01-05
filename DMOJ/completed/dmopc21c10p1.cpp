#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool isConsonant(char c) {
    return (c == 'k' || c == 'n' || c == 'h' || c == 'm' || c == 'r');
}

bool checkString(string s) {
    for (int j = 0; j < s.size(); j++) {
        char c = s[j];
        if (isVowel(c)) {
            continue;
        }
        if (isConsonant(c)) {
            if (c == 'h' && s[j + 1] == 'u') {
                return false;
            }
            if (isVowel(s[j + 1])) {
                j++;
                continue;
            }
        }
        if (c == 'f' && s[j + 1] == 'u') {
            j++;
            continue;
        }
        return false;
    }
    return true;
}

int main() {
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (checkString(s)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
