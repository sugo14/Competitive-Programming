#include <bits/stdc++.h>
using namespace std;

int currPos;
string s1, s2;

int main() {
    cin >> s1 >> s2;
    if (s2.size() > s1.size()) {
        cout << "no" << endl;
        return 0;
    }
    s1.push_back('!');
    for (int i = 0; i < s1.size(); i++) {
        currPos = 0;
        while (currPos < s2.size() && s2[currPos] == s1[currPos]) {
            currPos++;
        }
        while (currPos < s2.size() && s2[currPos] == s1[s1.size() - s2.size() + currPos]) {
            currPos++;
        }
        if (currPos >= s2.size()) {
            cout << "yes" << endl;
            return 0;
        }
        char c = s1[0];
        s1.erase(0, 1);
        s1.push_back(c);
    }
    cout << "no" << endl;
    return 0;
}
