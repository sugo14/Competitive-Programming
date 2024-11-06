#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int curr = 1, big = 0;
    char last = '\0';
    for (char c : s) {
        if (c == last) {
            curr++;
        }
        else {
            big = max(big, curr);
            curr = 1;
            last = c;
        }
    }
    big = max(big, curr);
    cout << big << endl;
    return 0;
}