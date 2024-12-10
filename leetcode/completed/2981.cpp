#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> lists[26];
public:
    int maximumLength(string s) {
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] != s[i]) {
                lists[s[i - 1] - 'a'].push_back(cnt);
                cnt = 0;
            }
            cnt++;
        }
        lists[s.back() - 'a'].push_back(cnt);
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lists[i].empty()) { continue; }
            sort(lists[i].begin(), lists[i].end(), greater<int>());

            ans = max(ans, lists[i][0] - 2);
            if (lists[i].size() == 1) { continue; }

            ans = max(ans, min(lists[i][0] - 1, lists[i][1]));
            if (lists[i].size() == 2) { continue; }
            
            ans = max(ans, min(lists[i][1], min(lists[i][1], lists[i][2])));
        }
        return (ans <= 0 ? -1 : ans);
    }
};
