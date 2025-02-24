#include <bits/stdc++.h>
using namespace std;

int n, cnt[1005], maxIndex, maxIndex2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    maxIndex = 0, maxIndex2 = 0;
    for (int i = 1000; i >= 1; i--) {
        if (cnt[i] > cnt[maxIndex]) { maxIndex = i; }
    }
    for (int i = 1; i <= 1000; i++) {
        if (cnt[i] > cnt[maxIndex2] && i != maxIndex) { maxIndex2 = i; }
    }
    int oldDif = abs(maxIndex - maxIndex2);
    maxIndex = 0, maxIndex2 = 0;
    for (int i = 1; i <= 1000; i++) {
        if (cnt[i] > cnt[maxIndex]) { maxIndex = i; }
    }
    for (int i = 1000; i >= 1; i--) {
        if (cnt[i] > cnt[maxIndex2] && i != maxIndex) { maxIndex2 = i; }
    }
    cout << max(oldDif, abs(maxIndex - maxIndex2)) << endl;
}
