#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Compare {
    bool operator()(pair<ll, ll>& a, pair<ll, ll>& b) { return a.first > b.first; }
};

class Solution {
public:
    ll shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> pq;
        pq.push({0, -1});
        ll currSum = 0, ans = LLONG_MAX;
        for (ll r = 0; r < nums.size(); r++) {
            currSum += nums[r];
            pair<ll, ll> p = pq.top();
            while (!pq.empty() && currSum - p.first >= k) {
                ans = min(ans, r - p.second);
                pq.pop();
                p = pq.top();
            }
            pq.push({currSum, r});
        }
        return (ans == LLONG_MAX) ? -1 : ans;
    }
};
