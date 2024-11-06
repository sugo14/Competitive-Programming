#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1" << endl;
        return 0;
    }
    if (n <= 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int left = n / 2, right = n - (n % 2 == 1);
    for (int i = 0; i < n / 2; i++) {
        cout << left-- << " " << right--;
        if (i != n / 2 - 1) {
            cout << " ";
        }
    }
    if (n % 2 == 1) {
        cout << " " << n;
    }
    cout << endl;
    return 0;
}
