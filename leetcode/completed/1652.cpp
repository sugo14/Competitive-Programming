#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> code2;
        for (int i = 0; i < code.size(); i++) {
            code2.push_back(0);
            for (int j = 0; j < abs(k); j++) {
                if (k > 0) { code2[i] += code[(i + j + 1) % code.size()]; }
                else if (k < 0) { code2[i] += code[(i - j - 1 + code.size()) % code.size()]; }
            }
        }
        return code2;
    }
};
