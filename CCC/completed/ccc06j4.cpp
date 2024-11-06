#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generatedPerms;
void generatePerms(vector<int> gen, vector<int> curr) {
    if (curr.size() == 0) {
        generatedPerms.push_back(gen);
        return;
    }
    for (int i = 0; i < curr.size(); i++) {
        vector<int> nextGen = gen;
        nextGen.push_back(curr[i]);
        vector<int> nextCurr = curr;
        nextCurr.erase(nextCurr.begin() + i);
        generatePerms(nextGen, nextCurr);
    }
}

int main() {
    generatePerms({}, {1, 2, 3, 4, 5, 6, 7});
    map<int, set<int>> disallowed = {
        {7, {1}},
        {1, {2}},
        {4, {1, 3}},
        {5, {3}}
    };
    int x, y;
    cin >> x >> y;
    while (x != 0 && y != 0) {
        disallowed[y].insert(x);
        cin >> x >> y;
    }
    vector<vector<int>> goodPerms;
    for (int i = 0; i < generatedPerms.size(); i++) {
        bool good = true;
        for (int j = 0; j < generatedPerms[i].size(); j++) {
            for (int k = j + 1; k < generatedPerms[i].size(); k++) {
                if (disallowed[generatedPerms[i][j]].find(generatedPerms[i][k]) != disallowed[generatedPerms[i][j]].end()) {
                    good = false;
                    break;
                }
            }
        }
        if (good) {
            goodPerms.push_back(generatedPerms[i]);
        }
    }
    if (goodPerms.size() == 0) {
        cout << "Cannot complete these tasks. Going to bed." << endl;
        return 0;
    }
    sort(goodPerms.begin(), goodPerms.end());
    for (int i = 0; i < goodPerms[0].size(); i++) {
        cout << goodPerms[0][i];
        if (i != goodPerms[0].size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
