#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, sum = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << (n * (n + 1) / 2) - sum << endl;
    return 0;
}
