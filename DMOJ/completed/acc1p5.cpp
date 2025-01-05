#include <bits/stdc++.h>
using namespace std;

double a[200001], b[200001];
priority_queue<pair<double, int>> pq;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    for (int i = 0; i < n; i++) { cin >> b[i]; }
    for (int i = 0; i < n; i++) { pq.push({((a[i] + 1) / (b[i] + 1)) - a[i] / b[i], i}); }
    for (int i = 0; i < k; i++) {
        int x = pq.top().second;
        pq.pop();
        a[x]++;
        b[x]++;
        pq.push({((a[x] + 1) / (b[x] + 1)) - a[x] / b[x], x});
    }
    double ans = 0;
    for (int i = 0; i < n; i++) { ans += a[i] / b[i]; }
    cout << setprecision(9) << ans * 100 / n << endl;
}
