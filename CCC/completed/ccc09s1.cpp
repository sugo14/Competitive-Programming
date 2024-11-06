#include <bits/stdc++.h>
using namespace std;

long long a = 1, b = 1, low, high, ans = 0;

int main(){
    cin >> low >> high;
    while (a * a < low) {
        a++;
    }
    while (b * b * b < low) {
        b++;
    }
    while ((a * a <= high) && (b * b * b <= high)) {
        if (a * a == b * b * b) {
            ans++;
            a++;
            b++;
        }
        else if (a * a > b * b * b) {
            b++;
        }
        else {
            a++;
        }
    }
    cout << ans << endl;
    return 0;
}
