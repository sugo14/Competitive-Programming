#include <bits/stdc++.h>
using namespace std;

class Solution {
    int cnt[100005];
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        for (vector<int> e : edges)  { cnt[e[1]]++; }
        int win = -1;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > 0) {
                if (win == -1) { win = i; }
                else { return -1; }
            }
        }
        return win;
    }
};
