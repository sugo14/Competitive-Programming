#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a == 0 || b == 0) {
        cout << "0";
        return 0;
    }
    cout << a + b;
    return 0;
}
