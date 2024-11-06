#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

bool isRepeating(vector<int> subVec, int start) {
    int ans;
    for (int i = 0; i < a.size(); i++) {
        if (subVec[i % subVec.size()] != a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    while (n != 0) {
        a = {};
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        if (n == 1) {
            cout << 0 << endl;
            cin >> n;
            continue;
        }
        vector<int> temp;
        for (int i = 1; i < n; i++) {
            temp.push_back(a[i] - a[i - 1]);
        }
        a = temp;
        vector<int> shortestRepeating;
        for (int i = 1; i < a.size() + 1; i++) {
            vector<int> subVec = {a.begin(), a.begin() + i};
            bool repeating = isRepeating(subVec, i);
            if (repeating) {
                cout << i << endl;
                break;
            }
        }
        cin >> n;
    }
    return 0;
}
