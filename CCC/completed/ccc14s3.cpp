#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vOrig(n), v;
        for (int i = 0; i < n; i++) { cin >> vOrig[i]; }
        reverse(vOrig.begin(), vOrig.end());
        /* cout << "vOrig: ";
        for (int x : vOrig) { cout << x << " "; }
        cout << endl; */

        int x = 1;
        for (int i = 0; i < n; i++) {
            while (v.size() > 0 && v[v.size() - 1] == x) {
                v.pop_back();
                x++;
                continue;
            }
            bool flag = false;
            if (vOrig[i] == x) {
                x++;
                flag = true;
            }
            while (v.size() > 0 && v[v.size() - 1] == x) {
                v.pop_back();
                x++;
                continue;
            }
            if (!flag) {
                v.push_back(vOrig[i]);
            }
        }
        reverse(v.begin(), v.end());
        /*
        cout << "v: ";
        for (int x : v) { cout << x << " "; }
        cout << endl; */
    
        bool good = true;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != x + i) {
                good = false;
                break;
            }
        }
        cout << (good ? "Y" : "N") << endl;
    }
}
