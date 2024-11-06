#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> thing;
    do {
        thing.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << thing.size() << '\n';
    for (int i = 0; i < thing.size(); i++) {
        cout << thing[i];
        if (i != thing.size() - 1) {
            cout << '\n';
        }
        else {
            cout << endl;
        }
    }
    return 0;
}
