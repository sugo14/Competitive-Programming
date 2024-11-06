#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x - 1] = i;
    }
    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) { rounds++; }
    }
    cout << rounds << endl;
    return 0;
}
