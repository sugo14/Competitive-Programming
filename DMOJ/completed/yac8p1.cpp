#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int start = 0, seenMax = 0, ans = 0;
    for (int end = start; end < n; end++) {
        int a = v[end];
        if (a == end + 1 && start < end && a > seenMax) {
            // cout << "SORTING FROM " << start << " TO " << end - 1 << " AT COST OF " << end - start << endl;
            ans += end - start;
            start = end + 1;
            seenMax = INT_MIN;
        }
        else if (a == end + 1 && (v[end - 1] == end || end == 0) && a > seenMax) {
            start++;
            seenMax = a;
        }
        else {
            seenMax = max(seenMax, a);
        }
    }
    // cout << "SORTING FROM " << start << " TO " << n - 1 << " AT COST OF " << n - start << endl;
    if (start < n - 1) {
        ans += n - start;
    }
    cout << ans;
    return 0;
}
