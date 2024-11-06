#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n % 2 == 0) { return false; }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) { return false; }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int l = a, r = a;
        while (!(isPrime(l) && isPrime(r))) { l--; r++; }
        cout << l << " " << r << endl;
    }
    return 0;
}
