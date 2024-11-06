#include <bits/stdc++.h>
using namespace std;

// extremely overengineered

int main() {
    long long n, m, k, biggest = 0;
    cin >> n >> m >> k;
    long long extraSamples = k - n;
    if (extraSamples < 0) {
        cout << "-1" << endl;
        return 0;
    }
    vector<long long> a(n);
    long long i, cnt = 2, loops = 0;
    a[0] = 1;
    for (i = 1; i < n; i++) {
        if (cnt > m) {
            cnt = 1;
            loops++;
        }
        if (extraSamples > 0) {
            if (loops > 0) {
                if (cnt == 1) {
                    if (extraSamples >= (m - 1)) {
                        a[i] = cnt;
                        //cout << i << " " << m - 1 << endl;
                        extraSamples -= m - 1;
                        cnt++;
                        if (cnt > m) {
                            cnt = 1;
                            loops++;
                        }
                    }
                    else { break; }
                }
                else {
                    if (extraSamples >= (2 * cnt - (cnt - 1) - 2) + (m - cnt)) {
                        a[i] = cnt;
                        extraSamples -= 2 * cnt - (cnt - 1) - 2 + (m - cnt);
                        //cout << i << " " << cnt << " " << 2 * cnt - (cnt - 1) - 2 + (m - cnt) << endl;
                        cnt++;
                        if (cnt > m) {
                            cnt = 1;
                            loops++;
                        }
                    }
                    else { break; }
                }
            }
            else {
                if (extraSamples >= 2 * cnt - (cnt - 1) - 2) {
                    a[i] = cnt;
                    extraSamples -= 2 * cnt - (cnt - 1) - 2;
                    //cout << i << " " << 2 * cnt - (cnt - 1) - 2 << endl;
                    cnt++;
                    if (cnt > m) {
                        cnt = 1;
                        loops++;
                    }
                }
                else { break; }
            }
        }
        else { break; }
    }
    //cout << "finished loop 1" << endl;
    for (long long j = 0; j < n; j++) { biggest = max(biggest, a[j]); }
    for (; i < n; i++) {
        if (extraSamples >= (biggest - 1)) {
            a[i] = a[i - biggest];
            //cout << i << " " << a[i - biggest] << endl;
            extraSamples -= biggest - 1;
        }
        else if (extraSamples > 0) {
            a[i] = a[i - extraSamples - 1];
            //cout << i << " " << extraSamples << endl;
            extraSamples = 0;
        }
        else { break; }
    }
    //cout << "finished loop 2" << endl;
    for (; i < n; i++) { a[i] = a[i - 1]; }
    if (extraSamples > 0) {
        cout << "-1" << endl;
        return 0;
    }
    for (long long i = 0; i < n; i++) { cout << a[i] << (i == n - 1 ? "" : " "); }
    cout << endl;
    return 0;
}
