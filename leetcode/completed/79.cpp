#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<char>> _board;
    string _word;

    bool dfs(int i, int j, int it) {
        if (it == _word.size()) { return true; }
        if (i < 0 || i >= _board.size() || j < 0 || j >= _board[0].size() || _board[i][j] != _word[it]) { return false; }
        it++;
        char c = _board[i][j];
        _board[i][j] = '\0';
        bool b = dfs(i - 1, j, it) || dfs(i + 1, j, it) || dfs(i, j - 1, it) || dfs(i, j + 1, it);
        _board[i][j] = c;
        return b;
    }

public:
    Solution() { }

    bool exist(vector<vector<char>>& board, string word) {
        _board = board;
        _word = word;
        reverse(_word.begin(), _word.end());
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(i, j, 0)) { return true; }
            }
        }
        return false;
    }
};
