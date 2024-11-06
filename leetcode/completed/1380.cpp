#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> minRows, maxCols;
        for (int i = 0; i < matrix.size(); i++) {
            int small = INT_MAX;
            for (int j = 0; j < matrix[i].size(); j++) { small = min(matrix[i][j], small); }
            cout << small << endl;
            minRows.push_back(small);
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            int big = 0;
            for (int i = 0; i < matrix.size(); i++) { big = max(big, matrix[i][j]); }
            cout << big << endl;
            maxCols.push_back(big);
        }
        sort(minRows.begin(), minRows.end());
        sort(maxCols.begin(), maxCols.end());
        vector<int> ans;
        int i = 0, j = 0;
        while (i != minRows.size() && j != maxCols.size()) {
            if (minRows[i] > maxCols[j]) { j++; }
            else if (minRows[i] < maxCols[j]) { i++; }
            else {
                ans.push_back(minRows[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<vector<int>> matrix = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    vector<int> ans = s.luckyNumbers(matrix);
    for (int i = 0; i < ans.size(); i++) { cout << ans[i] << " "; }
    cout << endl;
    return 0;
}
