#include <bits/stdc++.h>
using namespace std;

int n, s, t, totalPower = 0;
vector<int> all, l, r;

int main() {
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        all.push_back(x);
        totalPower += x;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += all[i];
        if ((i + 1) % s == 0 || i == n - 1) {
            l.push_back(sum);
            sum = 0;
        }
    }
    /* cout << "l: ";
    for (int i = 0; i < l.size(); i++) {
        cout << l[i] << " ";
    }
    cout << endl; */
    for (int i = 0; i < n; i++) {
        sum += all[all.size() - i - 1];
        if ((i + 1) % s == 0 || i == n - 1) {
            r.push_back(sum);
            sum = 0;
        }
    }
    /* cout << "r: ";
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << " ";
    }
    cout << endl; */
    int ans = 0;
    for (int i = 0; i < min((int) l.size(), t); i++) {
        ans += l[i];
    }
    int bestAns = ans;
    for (int i = 0; i < min((int) r.size(), t); i++) {
        ans -= l[min((int) l.size(), t) - i - 1];
        ans += r[i];
        bestAns = max(bestAns, ans);
    }
    cout << min(totalPower, bestAns) << endl;
    return 0;
}
