#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long ans = 0, small = INT_MAX, negCnt = 0;
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                ans += abs(matrix[i][j]);
                small = min(small, (long long)abs(matrix[i][j]));
                if (matrix[i][j] < 0) { negCnt++; }
            }
        }
        return negCnt % 2 ? ans - small * 2 : ans;
    }
};
