#include <bits/stdc++.h>
using namespace std;

// O(n^3) isnt great but its near 50% so it is what it is

class Solution {
    int thing[201];
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int big = 0;
        for (int i = 0; i < matrix.size(); i++) {
            // create histogram
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') { thing[j]++; }
                else { thing[j] = 0; }
            }
            // find max rectangle
            for (int j = 0; j < matrix[0].size(); j++) {
                int currMin = INT_MAX;
                for (int k = j; k < matrix[0].size(); k++) {
                    currMin = min(currMin, thing[k]);
                    big = max(big, currMin * (k - j + 1));
                }
            }
        }
        return big;
    }
};
