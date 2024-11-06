#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    vector<int> v;
    int big = 0, left = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (s.find(x) != s.end()) {
            while (v[left] != x) {
                s.erase(v[left]);
                left++;
            }
            left++;
        }
        s.insert(x);
        v.push_back(x);
        big = max(big, i - left + 1);
    }
    cout << big << endl;
    return 0;
}
