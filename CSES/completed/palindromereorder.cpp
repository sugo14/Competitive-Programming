#include <bits/stdc++.h>
using namespace std;

int arr[26];

string recursivelyGenerate(char oddChar, int n = 0) {
    int num = arr[n] / 2;
    if (n == 25) {
        return string(num, n + 'A') + (oddChar == '\0' ? "" : string(1, oddChar)) + string(num, n + 'A');
    }
    return string(num, n + 'A') + recursivelyGenerate(oddChar, n + 1) + string(num, n + 'A');
}

int main() {
    string s;
    cin >> s;
    for (char c : s) {
        arr[c - 'A']++;
    }
    bool odd = (s.size() % 2 == 1);
    char oddChar = '\0';
    for (int i = 0; i < 26; i++) {
        if (arr[i] % 2 == 1) {
            if (!odd) {
                cout << "NO SOLUTION" << endl;
            }
            odd = false;
            oddChar = 'A' + i;
        }
    }
    cout << recursivelyGenerate(oddChar) << endl;
}
