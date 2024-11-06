#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long curr = 0, big = INT_MIN;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        curr = max(curr + x, x);
        big = max(big, curr);
    }
    cout << big << endl;
    return 0;
}
