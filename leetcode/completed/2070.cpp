#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<pair<int, int>> newItems = {{0, 0}};
        for (int i = 0; i < items.size(); i++) {
            int price = items[i][0], beauty = items[i][1];
            int topPrice = newItems[newItems.size() - 1].first, topBeauty = newItems[newItems.size() - 1].second;
            if (beauty > topBeauty) { newItems.push_back({price, beauty}); }
        }
        set<pair<int, int>> s;
        for (int i = 0; i < newItems.size(); i++) { s.insert(newItems[i]); }
        vector<int> result;
        for (int i = 0; i < queries.size(); i++) {
            auto it = s.upper_bound({queries[i], INT_MAX});
            it--;
            result.push_back(it->second);
        }
        return result;
    }
};
