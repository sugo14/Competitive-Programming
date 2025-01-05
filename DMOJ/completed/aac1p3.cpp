#include <bits/stdc++.h>
using namespace std;

int n, x;

int main(){
    cin >> n >> x;
    if (n % 2 != x % 2) {
        cout << "-1" << endl;
        return 0;
    }
    for (int i = 0; i < min(x + 1, n); i++) {
        cout << "1";
        if (i != n - 1) {
            cout << " ";
        }
    }
    for (int i = x + 1; i < n; i++) {
        if ((i - (x + 1)) % 2 == 0) {
            cout << "2";
        }
        else {
            cout << "1";
        }
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
