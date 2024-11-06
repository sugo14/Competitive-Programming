#include <bits/stdc++.h>
using namespace std;

std::vector<int> chores;
int ans = 0;

int main() {
    int totalT, n;
    cin >> totalT >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        chores.push_back(t);
    }
    sort(chores.begin(), chores.end());
    for (int chore : chores) {
        if (totalT < chore) {
            break;
        }
        totalT -= chore;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
