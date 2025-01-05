#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int x = a * b, y = 80 * b;
    int ans = y - x + 80;
    cout << (ans > 100 ? -1 : max(0, ans)) << endl;
}
