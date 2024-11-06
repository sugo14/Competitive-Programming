#include <bits/stdc++.h>
using namespace std;

int k;
string code, ans;

char unshift(char c, int pos) {
    int shift = 3 * (pos + 1) + k;
    int letter = c - 'A';
    int letterNum = (letter - shift) % 26;
    if (letterNum < 0) letterNum += 26;
    return (char) letterNum + 'A';
}

int main() {
    cin >> k >> code;
    for (int i = 0; i < code.size(); i++) {
        char c = code[i];
        ans.push_back(unshift(c, i));
    }
    cout << ans << endl;
    return 0;
}
