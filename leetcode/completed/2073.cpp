#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        for (int i = 0; i < tickets.size(); i++) {
            ans += min(tickets[k], tickets[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> tickets = {2, 3, 2};
    int k = 2;
    Solution s;
    cout << s.timeRequiredToBuy(tickets, k) << endl;
    return 0;
}
