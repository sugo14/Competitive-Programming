#include <bits/stdc++.h>
using namespace std;

class Solution {
    set<vector<vector<int>>> visited;
    vector<vector<int>> solvedState = {{1, 2, 3}, {4, 5, 0}};

    void addNewStates(int zeroRow, int zeroCol, int swapRow, int swapCol, vector<vector<int>> newState, vector<vector<vector<int>>>& nextStates) {
        if (swapRow >= 0 && swapRow < newState.size() && swapCol >= 0 && swapCol < newState[0].size()) {
            swap(newState[zeroRow][zeroCol], newState[swapRow][swapCol]);
            if (visited.find(newState) != visited.end()) { return; }
            visited.insert(newState);
            nextStates.push_back(newState);
        }
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<vector<int>>> currStates = {board};
        int ans = 0;

        while (currStates.size() > 0) {
            vector<vector<vector<int>>> nextStates;
            for (auto& state : currStates) {
                // if solved return depth
                if (state == solvedState) { return ans; }
                // find zero pos
                int zeroRow = -1, zeroCol = -1;
                for (int i = 0; i < state.size(); i++) {
                    for (int j = 0; j < state[i].size(); j++) {
                        if (state[i][j] == 0) {
                            zeroRow = i;
                            zeroCol = j;
                        }
                    }
                }
                // add all new states
                vector<vector<int>> newState = state;
                addNewStates(zeroRow, zeroCol, zeroRow + 1, zeroCol, newState, nextStates);
                newState = state;
                addNewStates(zeroRow, zeroCol, zeroRow - 1, zeroCol, newState, nextStates);
                newState = state;
                addNewStates(zeroRow, zeroCol, zeroRow, zeroCol + 1, newState, nextStates);
                newState = state;
                addNewStates(zeroRow, zeroCol, zeroRow, zeroCol - 1, newState, nextStates);
            }
            currStates = nextStates;
            ans++;
        }
        return -1;
    }
};