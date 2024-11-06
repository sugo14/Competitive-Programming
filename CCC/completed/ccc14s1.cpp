#include <bits/stdc++.h>
using namespace std;

std::vector<int> things;
int x, n, a;

int main() {
    cin >> x;
    for (int i = 0; i < x; i++) {
        things.push_back(i + 1);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        vector<int> temp;
        for (int j = 0; j < things.size(); j++) {
            if ((j + 1) % a != 0) {
                temp.push_back(things[j]);
            }
        }
        things = temp;
    }
    for (int n : things) {
        cout << n << endl;
    }
    return 0;
}
