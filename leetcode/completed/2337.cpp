#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int l = 0, r = 0;
        for (int i = 0; i < start.size(); i++) {
            if (target[i] == 'L') {
                if (r > 0) { return false; }
                l++;
            }
            if (start[i] == 'L') { l--; }
            if (target[i] == 'R') { r--; }
            if (start[i] == 'R') {
                if (l > 0) { return false; }
                r++;
            }
            if (l < 0 || r < 0) { return false; }
        }
        return l == 0 && r == 0;
    }
};
