#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    bitset<1073741825> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (s[a ^ x]) {
            cout << "YES" << endl;
            return 0;
        }
        s[a] = true;
    }
    cout << "NO" << endl;
    return 0;
}
