#include <bits/stdc++.h>
using namespace std;

multiset<int> lengths;
set<int> lights = {0};

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    // the above is the difference between passing or not (0.98s->0.58s)
    int l, n;
    cin >> l >> n;
    lengths.insert(l);
    lights.insert(l);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = lights.insert(x).first;
        auto it2 = it, it3 = it;
        int a, b;
        it2--; a = *it2;
        it3++; b = *it3;
        lengths.erase(lengths.find(b - a));
        lengths.insert(x - a);
        lengths.insert(b - x);
        int big = *lengths.rbegin();
        cout << big << ' ';
    }
}
