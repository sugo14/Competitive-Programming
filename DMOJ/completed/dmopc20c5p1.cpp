#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int keystrokes = a.size() + b.size();
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] != b[i]) {
            break;
        }
        keystrokes -= 2;
    }
    cout << keystrokes << endl;
}
