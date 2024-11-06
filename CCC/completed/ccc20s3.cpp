#include <bits/stdc++.h>
using namespace std;

#define ll long long

int occ[200001][26];
int needle[26];

#define mod1 1000000000000099ll
#define prime1 29

ll maxValue1 = 1;

ll hash1(ll hashValue, char add, char remove) {
    hashValue = (hashValue * prime1 - (remove - 'a') * maxValue1 + (add - 'a')) % mod1;
    while (hashValue < 0) { hashValue += mod1; }
    return hashValue;
}
ll hashRange1(const string &s, ll l, ll r) {
    ll hashValue = 0;
    for (ll i = l; i <= r; i++) {
        hashValue = (hashValue * prime1 + (s[i] - 'a')) % mod1;
        while (hashValue < 0) { hashValue += mod1; }
    }
    return hashValue;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n, m;
    cin >> n >> m;
    for (ll i = 0; i < n.size(); i++) { maxValue1 *= prime1; maxValue1 %= mod1; }
    for (ll i = 0; i < n.size(); i++) { needle[n[i] - 'a']++; }
    for (ll i = 0; i < m.size(); i++) { occ[i][m[i] - 'a']++; }
    for (ll i = 1; i < m.size(); i++) {
        for (ll j = 0; j < 26; j++) { occ[i][j] = occ[i - 1][j] + occ[i][j]; }
    }
    if (n.size() > m.size()) { cout << 0 << endl; return 0; }
    unordered_set<ll> s;
    ll hashValue1 = 0;
    for (ll r = n.size() - 1; r < m.size(); r++) {
        ll l = r - n.size() + 1;
        if (l == 0) {
            hashValue1 = hashRange1(m, l, r);
        }
        else {
            hashValue1 = hash1(hashValue1, m[r], m[l - 1]);
        }
        for (ll i = 0; i < 26; i++) {
            if (occ[r][i] - (l == 0 ? 0 : occ[l - 1][i]) != needle[i]) { break; }
            else if (i == 25) {
                s.insert(hashValue1);
            }
        }
    }
    cout << s.size() << endl;
    return 0;
}
