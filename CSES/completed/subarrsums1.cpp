#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    int currSum = 0, i1 = 0, ans = 0;
    vector<int> v;
    for (int i2 = 0; i2 < n; i2++) {
        int x;
        cin >> x;
        currSum += x;
        v.push_back(x);
        while (currSum > t) {
            currSum -= v[i1];
            i1++;
        }
        if (currSum == t) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
