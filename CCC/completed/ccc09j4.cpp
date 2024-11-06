#include <bits/stdc++.h>
using namespace std;

int w;
vector<string> words = {
    "WELCOME",
    "TO",
    "CCC",
    "GOOD",
    "LUCK",
    "TODAY"
};
vector<string> signage = {};

void pad(vector<string> &v) {
    int totalWordLen = 0;
    string paddedString = "";
    for (int i = 0; i < v.size(); i++) {
        totalWordLen += v[i].size();
    }
    int totalSpacingLen = w - totalWordLen;
    std::vector<string> padding = std::vector<string>(max((int) v.size() - 1, 1), "");
    for (int i = 0; i < totalSpacingLen; i++) {
        padding[i % padding.size()].push_back('.');
    }
    for (int i = 0; i < v.size(); i++) {
        paddedString += v[i];
        if (i < v.size() - 1 || v.size() == 1) {
            paddedString += padding[i];
        }
    }
    signage.push_back(paddedString);
}

void solve() {
    int rowW = w;
    vector<string> wordArrangementRow = {};
    while (words.size() > 0) {
        string word = words[0];
        if ((int) word.size() > rowW) {
            pad(wordArrangementRow);
            wordArrangementRow = {};
            rowW = w;
            continue;
        }
        wordArrangementRow.push_back(word);
        rowW -= word.size();
        words.erase(words.begin());
        if (wordArrangementRow.size() > 0) {
            rowW -= 1;
        }
    }
    pad(wordArrangementRow);
}

int main() {
    cin >> w;
    solve();
    for (int i = 0; i < signage.size(); i++) {
        cout << signage[i] << endl;
    }
    return 0;
}
