#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        if (s.find(v[i]) != s.end()) {
            cout << "YES" << endl;
            return 0;
        }
        s.insert(v[i] ^ x);
    }
    cout << "NO" << endl;
    return 0;
}
