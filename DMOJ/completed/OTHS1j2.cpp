#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0, big = INT_MIN;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        big = max(big, x);
    }
    sum -= big;
    cout << (sum / (n - 1)) << endl;
    return 0;
}
