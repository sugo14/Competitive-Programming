#include <bits/stdc++.h>
using namespace std;

vector<int> letters;

int main() {
    letters = vector<int>(26, 0);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (char c : s1) {
        if (c < 'A' || c > 'Z') {
            continue;
        }
        letters[c - 'A']++;
    }
    for (char c : s2) {
        if (c < 'A' || c > 'Z') {
            continue;
        }
        letters[c - 'A']--;
    }
    for (int n : letters) {
        if (n != 0) {
            cout << "Is not an anagram." << endl;
            return 0;
        }
    }
    cout << "Is an anagram." << endl;
    return 0;
}
