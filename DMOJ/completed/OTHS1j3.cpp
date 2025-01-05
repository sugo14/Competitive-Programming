#include <bits/stdc++.h>
using namespace std;

int n, d, ans1 = 1, ans2 = 0;
vector<int> h;

int main(){
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        h.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int x = 1;
        while (i < n - 1 && abs(h[i + 1] - h[i]) <= d) {
            i++;
            x++;
        }
        ans1 = max(ans1, x);
        ans2++;
    }
    cout << ans2 << '\n' << ans1 << endl;
    return 0;
}
