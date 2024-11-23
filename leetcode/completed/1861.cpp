#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> ans(box[0].size(), vector<char>(box.size()));
        for (int i = 0; i < box.size(); i++) { box[i].push_back('*'); }
        for (int i = 0; i < box.size(); i++) {
            int currCount = 0;
            for (int j = 0; j < box[i].size(); j++) {
                if (box[i][j] == '*') {
                    for (int j2 = j - 1; j2 >= 0; j2--) {
                        if (box[i][j2] == '*') { break; }
                        else if (currCount > 0) {
                            box[i][j2] = '#';
                            currCount--;
                        }
                        else { box[i][j2] = '.'; }
                    }
                }
                else if (box[i][j] == '#') { currCount++; }
            }
        }
        for (int i = 0; i < box.size(); i++) {
            for (int j = 0; j < box[i].size() - 1; j++) { ans[j][box.size() - i - 1] = box[i][j]; }
        }
        return ans;
    }
};
