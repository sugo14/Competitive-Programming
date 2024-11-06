#include <bits/stdc++.h>
using namespace std;

int sizeToInt(char size) {
    if (size == 'S') {
        return 1;
    } else if (size == 'M') {
        return 2;
    } else if (size == 'L') {
        return 3;
    }
}

int jerseys[1000005];

int main() {
    int j, a;
    cin >> j >> a;
    for (int i = 1; i <= j; i++) {
        char c;
        cin >> c;
        jerseys[i] = sizeToInt(c);
    }
    int ans = 0;
    for (int i = 0; i < a; i++) {
        char size;
        int num;
        cin >> size >> num;
        if (jerseys[num] >= sizeToInt(size)) {
            ans++;
            jerseys[num] = -1;
        }
    }
    cout << ans << endl;
    return 0;
}
