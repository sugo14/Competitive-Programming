#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long sum = 0;
    for (int x : v) {
        if (x > (sum + 1)) {
            cout << sum + 1 << endl;
            return 0;
        }
        sum += x;
    }
    cout << sum + 1 << endl;
    return 0;
}
