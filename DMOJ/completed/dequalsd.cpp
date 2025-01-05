#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

long long modularExponentiation(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent = exponent / 2;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long l, r, k;
    cin >> l >> r >> k;
    if (k > 9) {
        cout << 0 << endl;
        return 0;
    }
    long long n = 10 - k;
    long long ans = modularExponentiation(10, r - 1) * n;
    ans -= ((l == 0) ? 0 : (modularExponentiation(10, l - 1) * n));
    ans += mod - (l == 0 ? 1 : 0);
    ans %= mod;
    cout << ans << endl;
    return 0;
}