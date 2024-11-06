#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int steps = 1, currX = 1, currY = 0, n = 0, currRow = rStart, currCol = cStart;
        vector<vector<int>> ans = {{rStart, cStart}};
        int n2 = 0;
        while (n2 < 5) {
            bool passedMatrixSquares = false;
            for (int i = 0; i < steps; i++) {
                currRow += currY;
                currCol += currX;
                // cout << currRow << " " << currCol << " " << currX << " " << currY << endl;
                if (currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols) {
                    passedMatrixSquares = true;
                    ans.push_back({currRow, currCol});
                }
            }
            if (!passedMatrixSquares) { n2++; }
            else { n2 = 0; }
            n++;
            if (n >= 2) {
                n = 0;
                int temp = currX;
                currX = -currY;
                currY = -temp;
                steps++;
            }
            else {
                int temp = currX;
                currX = currY;
                currY = temp;
            }
        }
        return ans;
    }
};