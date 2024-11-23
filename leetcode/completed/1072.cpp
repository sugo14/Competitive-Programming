#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, int> rows;
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            string s1 = "", s2 = "";
            for (int j = 0; j < matrix[i].size(); j++) {
                s1 += (char)('0' + matrix[i][j]);
                s2 += (s1[j] == '0' ? '1' : '0');
            }
            rows[s1]++;
            rows[s2]++;
        }
        int ans = 0;
        for (auto& pair : rows) { ans = max(ans, pair.second); }
        return ans;
    }
};
